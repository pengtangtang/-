/*
 * 视频采集模块
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#include <poll.h>

#include <mycamera.h>

/*
 *功能：打开并初始化摄像头
 *输入：
 *	struct videodev - 设备描述结构
 *输出：
 *	成功：0
 *  失败：-1
 */
int init_camera(struct videodev *vd)
{
	assert(NULL != vd);

	vd->fd = open(vd->devname, O_RDWR | O_NONBLOCK);
	if(0 > vd->fd){
		perror("init_camera-open");
		printf("ERR: init_camera, %s\n", vd->devname);
		return -1;
	}

	/*摄像头能力查询*/
	struct v4l2_capability cap;
	memset(&cap, 0, sizeof(struct v4l2_capability));
	if (0 > ioctl(vd->fd, VIDIOC_QUERYCAP, &cap)) {
		perror("init_camera-VIDIOC_QUERYCAP");
		goto ERR_STEP;
	}
	if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
		fprintf(stderr, 
			"video[%s]  capture not supported.\n", vd->devname);
		goto ERR_STEP;
	}
	if (!(cap.capabilities & V4L2_CAP_STREAMING)) {
		fprintf(stderr, 
			"%s does not support streaming i/o\n", vd->devname);
	}
	if (!(cap.capabilities & V4L2_CAP_READWRITE)) {
		fprintf(stderr, 
			"%s does not support read i/o\n", vd->devname);
	}

	int i = 6;
	/* enum video type */
	struct v4l2_fmtdesc fmtd;
	do{
		memset(&fmtd, 0, sizeof(fmtd));
		fmtd.index = 0;
		fmtd.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		if(ioctl(vd->fd, VIDIOC_ENUM_FMT, &fmtd) == 0){
			fmtd.index++;
			printf("{ pixelformat = ''%c%c%c%c'', description = ''%s'' }\n",
				fmtd.pixelformat & 0xFF, (fmtd.pixelformat >> 8) & 0xFF,
				(fmtd.pixelformat >> 16) & 0xFF, (fmtd.pixelformat >> 24) & 0xFF,
				fmtd.description);
		}
	}while(--i);

	/*设置数据格式*/
	struct v4l2_format vfmt;
	memset(&vfmt, 0, sizeof(vfmt));
	vfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	vfmt.fmt.pix.width = vd->w;
	vfmt.fmt.pix.height= vd->h;
	if(PICFMTYUV == vd->fmt){
		vfmt.fmt.pix.pixelformat= V4L2_PIX_FMT_YUYV;
	}else if(PICFMTJPG == vd->fmt){
		vfmt.fmt.pix.pixelformat= V4L2_PIX_FMT_MJPEG;
	}else{
		fprintf(stderr, 
			"%s video format not supported.\n", vd->devname);
		goto ERR_STEP;
	}
	vfmt.fmt.pix.field = V4L2_FIELD_ANY;  
	if(0 > ioctl(vd->fd, VIDIOC_S_FMT, &vfmt)){
		perror("init_camera-VIDIOC_S_FMT");
		goto ERR_STEP;
	}

	if ((vfmt.fmt.pix.width != vd->w) || (vfmt.fmt.pix.height != vd->h)){
		fprintf(stderr, \
			"Format asked unavailable get width %d height %d \n",\
			 vfmt.fmt.pix.width, vfmt.fmt.pix.height);
		vd->w = vfmt.fmt.pix.width;
		vd->h = vfmt.fmt.pix.height;
	}

	/*设置采样帧率*/
	static struct v4l2_streamparm fps;
	memset(&fps, 0, sizeof(struct v4l2_streamparm));
	fps.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(0 > ioctl(vd->fd, VIDIOC_G_PARM, &fps)){
		perror("init_camera-VIDIOC_S_PARM");
		goto ERR_STEP;
	}
	printf("fps: %d bps\n", 
		fps.parm.capture.timeperframe.denominator/fps.parm.capture.timeperframe.numerator);	

#if 0
	fps.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fps.parm.capture.timeperframe.numerator  = 1;
	fps.parm.capture.timeperframe.denominator= 5;
	if(0 > ioctl(vd->fd, VIDIOC_S_PARM, &fps)){
		perror("init_camera-VIDIOC_S_PARM");
		goto ERR_STEP;
	}
#endif

	/*申请帧缓存，一般不超过5个*/
	struct v4l2_requestbuffers vreqb;
	memset(&vreqb, 0, sizeof(vreqb));
	vreqb.count = vd->num;
	vreqb.type  = V4L2_BUF_TYPE_VIDEO_CAPTURE; 
	vreqb.memory= V4L2_MEMORY_MMAP;
	if(0 > ioctl(vd->fd, VIDIOC_REQBUFS, &vreqb)){
		perror("init_camera-VIDIOC_REQBUFS");
		goto ERR_STEP;
	}
	if(vd->num != vreqb.count){
		vd->num = vreqb.count;
	}

	printf("REQBUFS %d buffers success.\n", vd->num);
	
	/*将申请到的帧缓冲映射到用户空间*/
	vd->buffer = calloc(vd->num, sizeof(struct picbuf));
	if(0 == vd->buffer){
		perror("init_camera-calloc");
		goto ERR_STEP;
	}
	struct v4l2_buffer vbuf;
	for(i=0; i < vd->num; i++){
		memset(&vbuf, 0, sizeof(struct v4l2_buffer));
		vbuf.type  = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		vbuf.memory= V4L2_MEMORY_MMAP;
		vbuf.index = i;
		if(0 > ioctl(vd->fd,  VIDIOC_QUERYBUF, &vbuf)){
			perror("init_camera-VIDIOC_QUERYBUF");
			goto ERR_STEP;
		}

		vd->buffer[i].addr = mmap(NULL, vbuf.length,\
				     PROT_READ|PROT_WRITE, MAP_SHARED, vd->fd, vbuf.m.offset);
		if(MAP_FAILED == vd->buffer[i].addr){
			perror("init_camera-mmap");
			goto ERR_STEP1;
		}
		printf("%p: w=%d, h=%d, len=%d\n", vd->buffer[i].addr, vd->w, vd->h, vbuf.length);

		if(0 > ioctl(vd->fd, VIDIOC_QBUF, &vbuf)){
			perror("init_camera-VIDIOC_QBUF");
			goto ERR_STEP1;
		}
	}

	/* start to sample*/
	enum v4l2_buf_type vtype = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(0 > ioctl(vd->fd, VIDIOC_STREAMON, &vtype)){
		perror("init_camera-VIDIOC_STREAMON");
		goto ERR_STEP1;
	}

	return 0;
	
ERR_STEP1:
	for (i--; i >= 0; i--)
		munmap(vd->buffer[i].addr,vbuf.length);

ERR_STEP:
	close(vd->fd);
	return -1;
}

/*
 *功能：开始视频采集
 *输入：
 *	struct videodev *vd - 设备描述结构
 *	processimg：回调函数，提供给外部模块使用采集来的数据
 *	int timeout：超时值（单位毫秒）
 *	int loop：1 - 循环采集，0 - 采集一次
 *	void *arg ：传给回调函数的参数
 *输出：
 *	失败：-1
 */
int read_frame(struct videodev *vd,
			__processimg_fun processimg, 
			int timeout, int loop, void *arg)
{
	int ret = 0;
	struct pollfd fds;
	fds.fd = vd->fd;
	fds.events = POLLIN;

	struct picdata pic;

	do{
		ret = poll(&fds, 1, timeout);
		if(0 > ret){
			perror("init_camera-poll");
			break;
		}else if(0 == ret){
			fprintf(stderr, 
				"video[%s] timeout.\n", vd->devname);
			break;
		}

		struct v4l2_buffer vbuf;
		memset(&vbuf, 0, sizeof(struct v4l2_buffer));
		vbuf.type  = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		vbuf.memory= V4L2_MEMORY_MMAP;

		ret = ioctl(vd->fd, VIDIOC_DQBUF, &vbuf);
		if(0 > ret){
			perror("init_camera-VIDIOC_DQBUF");
			break;
		}

		pic.buffer= vd->buffer[vbuf.index].addr;
		pic.w     = vd->w;
		pic.h     = vd->h;
		pic.size  = vbuf.length;
		ret = processimg(&pic, arg);
		if(0 > ret){
			break;
		}

		ret = ioctl(vd->fd, VIDIOC_QBUF, &vbuf);
		if(0 > ret){
			perror("init_camera-VIDIOC_QBUF");
			break;
		}
	}while(loop);

	return ret;
}

/*
 *功能：关闭视频并做回收工作
 *输入：
 *  struct videodev *vd - 设备描述结构
 *输出：
 *	成功：0
 *  失败：-1
 */
int uninit_camera(struct videodev *vd)
{
	/* stop to sample*/
	enum v4l2_buf_type vtype = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(0 > ioctl(vd->fd, VIDIOC_STREAMOFF, &vtype))
		perror("init_camera-VIDIOC_STREAMOFF");

	int len = vd->w*vd->h*2;
	if(PICFMTJPG == vd->fmt)
		len = vd->w*vd->h;
	for (int i = 0; i < vd->num; ++i)
		if(0 > munmap(vd->buffer[i].addr,len))
			perror("init_camera-munmap");

	close(vd->fd);

	free(vd->buffer);

	return 0;
}
