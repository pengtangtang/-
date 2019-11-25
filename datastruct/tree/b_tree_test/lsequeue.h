/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：lsequeue.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LSEQUEUE_H
#define _LSEQUEUE_H
#include "tree.h"
/*链式队列：插入操作在队尾进行，删除操作在队头进行，由队头指针与队尾指针控制队列的操作*/
typedef int data_t;/*定义链式队列中数据元素的类型*/
typedef struct node{
	tree_t data;/*数据域，此处为b树结点指针*/
	struct node *next;/*链接指针域*/
}lseqnode;/*链表元素类型定义*/

typedef struct{
	lseqnode *front,*rear;/*链队列指针*/
}lsequeue;/*链队列类型定义*/

lsequeue *create_lsequeue();
int *create_is_empty(lsequeue *lq);
int in_lsequeue(lsequeue *lq,tree_t data);
tree_t out_lsequeue(lsequeue *lq);
int print_lsequeue(lsequeue *lq);


#endif
