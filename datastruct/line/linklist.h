/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linklist.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月06日
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

linklist *createlinklist();//创建头结点，返回指向头结点的指针
int getlinklistlength(linklist *head);//求链表的有效结点数（不含头结点）
int linklist_is_empty(linklist *head);//判断链表是否为空,即head->next是否为空（在堆区内存充足的情况，链表不会满）
int print_linklist(linklist *head);//链表的遍历
int insertlinklistbypos(linklist *head,data_t data,int pos);//对链表按位置插入数据
int dellinklistbypos(linklist *head,int pos);//按位置删除
int dallinklistbydata(linklist *head,data_t data);//按值删除
data_t searchlinklistbypos(linklist *head,int pos);//按位置查找返回值
int searchlinklistbydata(linklist *head,data_t data);//按值查找返回位置
int updatelinklistbypos(linklist *head,int pos,data_t data);//按位置更新值
int updatelinklistbydata(linklist *head,data_t old,data_t new);//用值进行更新
int daozhilinklist(linklist *head);//链表倒置
int clearlinklist(linklist *head);//清空链表
int destorylinklist(linklist **head);//摧毁链表
linklist *combine_linklist(linklist *head1,linklist *head2,linklist *newhead);//将两个有序链表合并
#endif
