/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：dlinklist.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _DLINKLIST_H
#define _DLINKLIST_H

typedef int data_t;
typedef struct node{
	data_t data;
	struct node *prior,*next;
}dlinklist;
dlinklist *createdlinklist();//创建双向链表
int dlinklist_is_empty(dlinklist *head);//判断链表是否为空
int insertdlinklistbypos(dlinklist *head,data_t data,int pos);//按位置插入
int print_dlinklist(dlinklist *head);//遍历双向链表
int del_dlinklistbypos(dlinklist *head,int pos);//按位置删除
int get_lengthdlinklist(dlinklist *head);//求链表长度
#endif
