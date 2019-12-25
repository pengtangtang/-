#include <stdio.h>
#include <string.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>  
#include <arpa/inet.h>

#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#include "mycamera.h"
#include "yuvtobmp.h"

/*摄像头的分辨率*/

#if 0
#define W 640
#define H 480
#else
#define W 800
#define H 600
#endif

static struct videodev video;

int init_server(u_short port, int backlog)
{
	int s = socket(AF_INET6, SOCK_STREAM, 0);
	if(0 > s){
		perror("socket");
		return -1;
	}

	int reuseaddr = 1;
	if(0 > setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr))){
		perror("can't reuse addr on rw socket!");
		return -1;
	}

	struct sockaddr_in6 addr = {
		.sin6_family	= AF_INET6,
		.sin6_port	= htons(port),
		.sin6_addr	= in6addr_any,
	};
	socklen_t addrlen = sizeof(addr);
	if(0 > bind(s, (struct sockaddr*) &addr, addrlen)){
		perror("bind");
		goto ERR_STEP;		
	}

	if(0 > listen(s, backlog)){
		perror("bind");
		goto ERR_STEP;
	}	

	return s;

ERR_STEP:
	close(s);
	return -1;
}

int sndimg(const struct picdata *pic, void *arg)
{
	int ret = 0;
	int rws = (int)arg;

	//把yuv转成jpeg
	u8 *picbuf = NULL;
	u32 len = getjpgbuff(&picbuf, pic->buffer, pic->w, pic->h);

	int size = htonl(len);
	if(4 != write(rws, &size, 4)){
		printf("send head fail.\n");
		ret = -1;
		goto NEXT_STEP;
	}

	void *p = picbuf;
	size = len;
	while(size){
		int num = send(rws, p, size, MSG_NOSIGNAL);
		if( 0 > num){
			printf("send content[%p] fail.\n", picbuf);
			ret = -1;
			goto NEXT_STEP;
		}
		printf("send %p:%d content done.\n", p, num);

		size-= num;
		p   += num;
	}

	printf("send jpeg[%dbytes] done.\n", len);

NEXT_STEP:
	freejpgbuff(picbuf);
	return ret;
}

int main()
{
	char devname[VDLEN];
	snprintf(devname, VDLEN, "/dev/video0");
	strncpy(video.devname, devname, VDLEN);
	video.w	= W;
	video.h	= H;
	video.fmt= PICFMTYUV;
	video.num= 5;

	if(0 > init_camera(&video)){
		return -1;
	}

	printf("Init camera[%s] done.\n", video.devname);

	//分配缓存：暂存转换数据
	init_conv(video.w, video.h);
	
	signal(SIGPIPE, SIG_IGN);

	int s = init_server(59999, 1);
	if(0 > s){
		return -1;
	}

	while(1){
		printf("Waiting for new client ...\n");
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		socklen_t addrlen = sizeof(addr);
		int rws  = accept(s, (struct sockaddr *)&addr, &addrlen);
		if(0 > rws){
			perror("accept");
			break;
		}
		printf("new con[%d]: %s:%d\n", rws,\
			inet_ntoa(addr.sin_addr),\
			ntohs(addr.sin_port));

		//循环采样
		if(0 > read_frame(&video, sndimg, 3000, 1, (void *)rws)){
			printf("read frame fail.\n");
		}

		close(rws);
	}

	close(s);
	uninit_camera(&video);
	uninit_conv();

	return 0;
}


