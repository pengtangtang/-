/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linklist.h
*   创 建 者：pengtangtang
*   创建日期：2019年09月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *next;
}linklist;

linklist *create_linklist();//创建链表，首先创建头结点
int empty_is_linklist(linklist *head);
int get_length_linklist(linklist *head);
int display_linklist(linklist *head);
int insert_linklist(linklist *head,data_t data,int pos);
int delete_bypos_linklist(linklist *head,int pos);
int delete_bydata_linklist(linklist *head,data_t data);
int convert_linklist(linklist *head);
int clear_linklist(linklist *head);
int destroy_linklist(linklist **head);
linklist *combine_linklist(linklist *head1,linklist *head2,linklist *newhead);
#endif
