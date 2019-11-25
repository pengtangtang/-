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
#include "linktree.h"
/*队列头出尾进*/
typedef int data_t;
typedef struct node{
	tree_t data;
	struct node *next;
}lseqnode;//循环链表结点
typedef struct{
	lseqnode *front,*rear;
}lsequeue;//指向头结点与队尾的指针
lsequeue *create_lsequeue();//创建循环队列
int lsequeue_is_empty(lsequeue *lq);//判断循环队列是否为空
int in_lsequeue(lsequeue *lq,tree_t data);//入队
tree_t out_lsequeue(lsequeue *lq);//出队
int print_lsequeue(lsequeue *lq);//遍历循环队列
#endif
