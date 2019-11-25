/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：lsequeue.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "lsequeue.h"
#include "tree.h"

lsequeue *create_lsequeue()/*创建队列*/
{
	lsequeue *lq = (lsequeue *)malloc(sizeof(lsequeue));
	if(NULL == lq)
		return NULL;
	/*队头队尾指针是指向队列结点的指针*/
	lq->front = lq->rear = (lseqnode *)malloc(sizeof(lseqnode));
	if(NULL == lq->front)
		return NULL;
	lq->front->data = NULL;
	lq->front->next = NULL;
	return lq;
}

int lsequeue_is_empty(lsequeue *lq)/*判断队列是否为空*/
{
	if(NULL == lq)
		return -1;
	return lq->front==lq->rear;
}

int in_lsequeue(lsequeue *lq,tree_t data)/*元素入队*/
{
	if(NULL == lq)
		return -1;
	lseqnode *new = (lseqnode *)malloc(sizeof(lseqnode));
	if(NULL == new)
		return -1;
	new->data = data;
	new->next = NULL;
	lq->rear->next = new;/*队尾入队*/
	lq->rear = new;
	return 0;
}

tree_t out_lsequeue(lsequeue *lq)/*元素出队*/
{
	if(lq==NULL || lsequeue_is_empty(lq))
		return NULL;
	lseqnode *p = lq->front->next;/*队头出队*/
	tree_t data = p->data;
	if(p == lq->rear)
		lq->rear = lq->front;
	lq->front->next = p->next;
	free(p);
	p=NULL;
	return data;
}
