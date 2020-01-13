/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：tcp_server.c
*   创 建 者：pengtangtang
*   创建日期：2020年01月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define err_log(err) do{perror(err);exit(-1);}while(0)

pthread_t pid1,pid2;


void* pthread_recv(void *arg)
{
	int sockfd = *(int *)arg;
	char buf[32] = {0};
	int ret = 0;
	while(1){
		ret = read(sockfd,buf,sizeof(buf));
		if(0 == ret){
			err_log("rea failed");
			pthread_cancel(pid2);
			break;
		}
		printf("recv:%s",buf);
		memset(buf,0,sizeof(buf));
	}
	pthread_exit(NULL);
}


void *pthread_send(void *arg)
{
	int sockfd = *(int *)arg;
	char buf[32] = {0};
	while(1){
		memset(buf,0,sizeof(buf));
	//	printf("send:");
		fgets(buf,sizeof(buf),stdin);
		if(write(sockfd,buf,sizeof(buf)) < 0)
		{
			err_log("write_failed");
		}
	}
	pthread_exit(NULL);
}

int main()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		err_log("sockfd failed");
	}

	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(8888);
	seraddr.sin_addr.s_addr = inet_addr("192.168.1.55");

	if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1)
	{
		err_log("connect failed");
	}

	if(pthread_create(&pid1,NULL,pthread_recv,&sockfd) < 0){
		err_log("pthread_create1 failed");
	}

	if(pthread_create(&pid2,NULL,pthread_send,&sockfd) < 0){
		err_log("pthread_create2 failed");
	}

	if(pthread_join(pid1,NULL) < 0){
		err_log("pthread_join failed");
	}

	if(pthread_join(pid2,NULL) < 0){
		err_log("pthread_join failed");
	}

	close(sockfd);
	return 0;
}
