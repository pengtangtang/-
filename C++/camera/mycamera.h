/*
 * 视频采集模块
 */
#ifndef MYCAMERA_H
#define MYCAMERA_H

/*
 * 采样图片格式
 * PICFMTYUV - yuyv422
 * PICFMTJPG - jpeg
 */
#define PICFMTYUV	0
#define PICFMTJPG	1

//采样数据的结构体
struct picdata{
	void *buffer;	//图片缓存首地址
	int     size;	//图片大小
	int        w;	//图片宽
	int        h;	//图片高
};

struct picbuf{
	void *addr;	
};

#define VDLEN 36
//摄像头设备结构体
struct videodev{
	char devname[VDLEN];	//设备文件
	int         w;		//采样实际高
	int         h;		//采样实际高
	int       fmt;		//采样格式
	int       num;		//缓存数量

	//private
	int        fd;		//设备文件描述符	
	struct picbuf *buffer;	//缓存数组首地址
};

/*
 *功能：打开并初始化摄像头
 *输入：
 *	struct videodev - 设备描述结构
 *输出：
 *	成功：0
 *	失败：-1
 */
int init_camera(struct videodev *vd);

/*
 *功能：关闭视频并做回收工作
 *输入：
 *	struct videodev *vd - 设备描述结构
 *输出：
 *	成功：0
 *	失败：-1
 */
int uninit_camera(struct videodev *vd);

/*
 *功能 回调函数-使用采集数据
 *输入：
 *	struct picdata *pic：图片数据结构体
 *	void *arg：传给回调函数的参数
 *输出：
 *	失败：-1
 */
typedef int (*__processimg_fun)(const struct picdata *pic, void *arg);

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
			int timeout, int loop, void *arg);

#endif
