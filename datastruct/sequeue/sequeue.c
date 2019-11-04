/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：sequeue.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "sequeue.h"

sequeue *create_sequeue()
{	
	sequeue *sq=(sequeue *)malloc(sizeof(sequeue));
	if(sq == NULL)
		return NULL;
	memset(sq->data,0,sizeof(sq->data));
	sq->front=sq->rear=0;
	return sq;
}
int queue_is_empty(sequeue *sq)
{
	if(sq==NULL)
		return -1;
	return sq->front==sq->rear;
}
int queue_is_full(sequeue *sq)
{
	if(sq==NULL)
		return -1;
	if(sq->rear > sq->front)
		return sq->rear - sq->front==SIZE-1;
	if(sq->rear < sq->front)
		return sq->front - sq->rear==1;
}
int inqueue(sequeue *sq,data_t data)
{
	if(sq==NULL || queue_is_full(sq))
		return -1; 
	sq->data[sq->rear] = data;
	sq->rear=(sq->rear+1)%SIZE;//rear向后移动一个，即使rear在最后一个，下一个下标为0，也成立
	return 0;
}
data_t outqueue(sequeue *sq)
{
	if(NULL == sq || queue_is_empty(sq))
		return -1;
	data_t data=sq->data[sq->front];
	sq->front=(sq->front+1)%SIZE;
	return data;
}
int print_queue(sequeue *sq)
{
	if(sq==NULL)
		return -1;
	int count=0;
	while(count!=sq->rear)
	{
		printf("%-2d",sq->data[count]);
		count=(count+1)%SIZE;
	}
	printf("\n");
	return 0;
}
