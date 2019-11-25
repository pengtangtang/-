/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：queue.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _QUEUE_H
#define _QUEUE_H

#define MAXSIZE 100
#define INFINITY 0
typedef int data_t;
typedef struct {
	int front,rear;
	data_t data[MAXSIZE];
}Queue;

void init_queue(Queue &Q);
void enter_queue(Queue &Q,data_t v);
data_t delete_queue(Queue &Q);
int empty_queue(Queue &Q);

#endif
