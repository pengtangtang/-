/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：dlinklist.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dlinklist.h"
dlinklist *createdlinklist()//创建链表
{
	dlinklist *head=(dlinklist *)malloc(sizeof(dlinklist));
	if(head == NULL)
		return NULL;
	head->data=-1;
	head->next=head;
	head->prior=head;
	return head;
}
int dlinklist_is_empty(dlinklist *head)//判断链表是否为空
{
	if(head == NULL)
		return -1;
	return head->next == head;
}
int get_lengthdlinklist(dlinklist *head)//求表长
{
	if(head == NULL)
		return -1;
	int len=0;
	dlinklist *p=head->next;
	while(p!=head)//注意循环链表的判断条件
	{
		len++;
		p=p->next;
	}
	return len;
}
int insertdlinklistbypos(dlinklist *head,data_t data,int pos)
{
	if((head == NULL) || pos<0 || pos>get_lengthdlinklist(head))
		return -1;
	//申请结点
	dlinklist *new=(dlinklist *)malloc(sizeof(dlinklist));
	if(new == NULL)
		return -1;
	new->data=data;
	new->prior=new->next=NULL;

	dlinklist *p=head;//找到待插入结点的前一结点
	while(pos--)
	{
		p=p->next;
	}
	//插入结点
	new->prior=p;
	new->next=p->next;
	p->next->prior=new;
	p->next=new;
	return 0;

}	
int print_dlinklist(dlinklist *head)
{
	if(head == NULL)
		return -1;
	dlinklist *p=head->next;
	while(p!=head)
	{
		printf("%-2d",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}

int del_dlinklist(dlinklist *head,int pos)
{
	if((head == NULL) || dlinklist_is_empty(head))
		return -1;
	dlinklist *p=head->next;
	while(pos--)
	{
		p=p->next;
	}
	//删除结点
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	p=NULL;
	return 0;
}
