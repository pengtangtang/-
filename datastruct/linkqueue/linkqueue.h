/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linkqueue.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#if 0
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *next;
}seqnode;//结点结构体
typedef struct {
	seqnode *front,*rear;
}lseqnode;//结点指针
lseqnode *createlsqueue();//创建链式队列
int lsequeue(lseqnode *lq);//判断队列是否为空
int inlsqueue(lseqnode *lq,data_t data);//入队
int print_lsqueue(lseqnode *lq);//遍历
int outlsqueue(lseqnode *lq);//出队
#endif
#if 1
typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}lseqnode;//循环链表结点
typedef struct{
	lseqnode *front,*rear;
}lsequeue;//指向头结点与队尾的指针
lsequeue *create_lsequeue();//创建循环队列
int lsequeue_is_empty(lsequeue *lq);//判断循环队列是否为空
int in_lsequeue(lsequeue *lq,data_t data);//入队
data_t out_lsequeue(lsequeue *lq);//出队
int print_lsequeue(lsequeue *lq);//遍历循环队列
#endif
#endif
