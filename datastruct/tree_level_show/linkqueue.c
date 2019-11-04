/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linkqueue.ce
*   创 建 者：pengtangtang
*   创建日期：2019年08月08日
*   描    述：

*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "linkqueue.h"
#if 0
lseqnode *createlsqueue()
{
	lseqnode *lq=(lseqnode *)malloc(sizeof(lseqnode));//指向头结点和堆为元素的指针
	if(lq==NULL)
		return 	NULL;
	lq->front=lq->rear=(seqnode *)malloc(sizeof(seqnode));//头结点，且结点指针指向结点
	if(lq->front==NULL)
		return NULL;
	lq->front->data=-1;
	lq->front->next=NULL;
	return lq;
}

int lsqueue_is_empty(lseqnode *lq)
{
	if(lq==NULL)
		return -1;
	return lq->front==lq->rear;
}
int inlsqueue(lseqnode *lq,data_t data)
{
	if(lq==NULL);
	return -1;
	seqnode *new=(seqnode *)malloc(sizeof(seqnode));
	if(new==NULL)
		return -1;
	new->data=data;
	new->next=NULL;
	//入队
	lq->rear->next=new;
	lq->rear=new;
	return 0;

}
int print_lsqueue(lseqnode *lq)
{
	if(lq==NULL)
		return -1;
	seqnode *p=lq->front->next;//第一个有小结点
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}
int outlsqueue(lseqnode *lq)
{
	if(lq==NULL || lsqueue_is_empty(lq))
		return -1;
	seqnode *p=lq->front->next;
	data_t data=p->data;
	if(p==lq->rear)//判断是否为最后一个结点，若是则将指向队尾的指针指向头结点，再删除
		lq->rear=lq->front;
	lq->front->next=p->next;//删除结点
	free(p);
	p=NULL;
	return data;
}
#endif
#if 1

lsequeue *create_lsequeue()//创建循环队列
{
	lsequeue *lq=(lsequeue *)malloc(sizeof(lsequeue));
	if(lq==NULL)
		return NULL;
	lq->front=lq->rear=(lseqnode *)malloc(sizeof(lseqnode));
	if(lq->front==NULL)
		return NULL;
	lq->front->data=NULL;
	lq->front->next=NULL;
	return lq;
}

int lsequeue_is_empty(lsequeue *lq)//判断循环队列是否为空
{
	if(lq==NULL)
		return -1;
	return lq->rear==lq->front;
}

tree_t  out_lsequeue(lsequeue *lq)//出队
{
	if(lq==NULL || lsequeue_is_empty(lq))
		return NULL;
	lseqnode *p=lq->front->next;//保存出队元素
	tree_t data=p->data;
	if(p==lq->rear)//判断出队元素是否为最后一个元素
		lq->rear=lq->front;//将队尾指针返回到头结点
	lq->front->next=p->next;
	free(p);
	p=NULL;
	return data;
}

int in_lsequeue(lsequeue *lq,tree_t  data)//入队
{
	if(lq==NULL)
		return -1;
	lseqnode *new=(lseqnode *)malloc(sizeof(lseqnode));//申请一个新的结点
	if(new==NULL)
		return -1;
	new->data=data;//为结点赋值
	new->next=NULL;
	lq->rear->next=new;//插入结点
	lq->rear=new;
	return 0;
}
#if 0
int print_lsequeue(lsequeue *lq)
{
	if(lq==NULL)
		return -1;
	lseqnode *p=lq->front->next;
	while(p!=NULL)
	{
		printf("%-2d ",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
#endif
#endif
