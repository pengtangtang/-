/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：sequeue.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _SEQUEUE_H
#define _SEQUEUE_H
//顺序队列
#define SIZE 100
typedef int data_t;
typedef struct seq{
	data_t data[SIZE];
	int front,rear;//对应数组下标
}sequeue;
sequeue *create_sequeue();//创建空队列
int queue_is_empty(sequeue *sq);//判断队列是否为空
int queue_is_full(sequeue *sq);//判断队列是否满队
int inqueue(sequeue *sq,data_t data);//入队
data_t outqueue(sequeue *sq);//出队
int print_queue(sequeue *sq);//遍历队列

#endif
