/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：queue.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "queue.h"

void init_queue(Queue &Q)
{
	Q.front = Q.rear = 0;
	
	for(int i=0;i<MAXSIZE;i++){
		Q.data[i] = INFINITY;
	}
}

void enter_queue(Queue &Q,data_t v)
{
#if 0
	if(Q.rear > Q.front)
	{
		if(Q.rear-Q.front == MAXSIZE-1)
		{
			printf("Queue is full\n");
			return ;
		}
	}

	if(Q.rear < Q.front)
	{
		if(Q.front-Q.rear == 1)
		{
			printf("Queue is full\n");
			return ;
		}
	}
#else
	if((Q.front+1)%MAXSIZE == Q.rear){
		printf("Queue is full\n");
		return ;
	}
#endif
	Q.data[Q.rear] = v;
	Q.rear = (++Q.rear)%MAXSIZE;
}

data_t delete_queue(Queue &Q){
	data_t i = Q.data[Q.front];
	Q.data[Q.front] = INFINITY;
	Q.front = (++Q.front)%MAXSIZE;
	return i;
}

int empty_queue(Queue Q){
	if(Q.front == Q.rear)
		return 0;
	return 1;
}
