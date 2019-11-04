/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linklist.c
*   创 建 者：pengtangtang
*   创建日期：2019年09月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "linklist.h"

linklist *create_linklist()
{//head头指针指向第一个结点
	linklist *head = (linklist *)malloc(sizeof(linklist));
	//空间申请后必须判断是否申请成功
	if(head == NULL)
		return NULL;
	head->next = NULL;
	head->data = -1;//头结点不存储数据
	return head;
}

int empty_is_linklist(linklist *head)
{
	if(head == NULL)
		return -1;
	return (head->next == NULL);
}

int get_length_linklist(linklist *head)
{
	if(head == NULL)
		return -1;
	int count = 0;
	linklist *p = head->next;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int display_linklist(linklist *head)
{
	if(head == NULL)
		return -1;
	linklist *p = head->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

int insert_linklist(linklist *head,data_t data,int pos)
{
	if(head == NULL)
		return -1;
	if(pos<0 || pos>(get_length_linklist(head)))//可以在后面插入
		return -1;
	linklist *q = (linklist *)malloc(sizeof(linklist));
	if(q == NULL)
		return -1;
	q->next = NULL;
	q->data = data;
	linklist *p = head;
//	int count = 0;
	while(pos--)
	{
		p = p->next;
//		count++;
	}
	q->next = p->next;
	p->next = q;
	return 0;

}

int delete_bypos_linklist(linklist *head,int pos)
{
	if(head == NULL)
		return -1;
	if(pos<0 || pos>get_length_linklist(head))
		return -1;
	linklist *p = head;
	while(pos--){
		p = p->next;
	}
	linklist *q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	return 0;



}

int convert_linklist(linklist *head)
{
	if(head == NULL)
		return -1;
	linklist *p = head->next;
	linklist *q;

	head->next = NULL;
	while(p){
		q = p->next;
		p->next = head->next;

		head->next = p;
		p = q;
	}
	return 0;
}

int delete_bydata_linklist(linklist *head,data_t data)
{
	if(head == NULL)
		return -1;
	linklist *p = head->next;
	int count = 0;
	while(p){
		count++;
		if(p->data == data)
			break;
		p = p->next;
	}
	delete_bypos_linklist(head,count-1);//按位置删除，所以count-1
	return 0;
	
}

int destroy_linklist(linklist **head)//head为头指针代表整个链表，销毁链表就必须销毁头指针
{
	if(head == NULL)
		return -1;
	clear_linklist(*head);//首先将链表清空在销毁
	free(*head);
	*head = NULL;
	return 0;
}

int clear_linklist(linklist *head)
{
	if(head == NULL)
		return -1;
	linklist *q,*p = head->next;
	while(p){//释放链表结点
		q = p;
		p = p->next;
		free(q);
	}

	head->next = NULL;//将整个链表清空
	return 0;
}


linklist *combine_linklist(linklist *head1,linklist *head2,linklist *newhead)
{
	if(head1==NULL || head2==NULL || newhead==NULL)
		return NULL;
	linklist *p = head1->next;
	linklist *q = head2->next;
	linklist *m = newhead;
	while(p && q){
		linklist *a = (linklist *)malloc(sizeof(linklist));
		if(a == NULL)
			return NULL;
		a->next = NULL;
		a->data = 0;
		if(p->data > q->data)
		{
			a->data = q->data;
			q = q->next;
		}
		else
		{
			a->data = p->data;
			p = p->next;
		}
		m->next = a;
		m = a;	

	}
	if(p)
		m->next = p;
	if(q)
		m->next = q;
	return newhead;


}
