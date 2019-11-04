/*===============================================================
 *   Copyright (C) 2019 All rights reserved.
 *   
 *   文件名称：linklist.c
 *   创 建 者：pengtangtang
 *   创建日期：2019年08月06日
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
linklist *createlinklist()
{
	linklist *head = (linklist *)malloc(sizeof(linklist));
	if(head == NULL)
		return NULL;
	head->data = -1;
	head->next = NULL;
	return head;
}
int getlinklistlength(linklist *head)
{
	if(head == NULL)
		return -1;
	int len = 0;
	linklist *p = head->next;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
int linklist_is_empty(linklist *head)
{
	if(head == NULL)
		return -1;
	return head->next == NULL;
}
int print_linklist(linklist *head)
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
int insertlinklistbypos(linklist *head,data_t data,int pos)
{
	if(head == NULL)
		return -1;
	if(pos < 0 || pos > getlinklistlength(head))
		return -1;
	linklist *new = (linklist *)malloc(sizeof(linklist));
	if(new == NULL)
		return -1;
	new->data = data;
	new->next = NULL;

	linklist *p = head;
	while(pos--)
	{
		p = p->next;
	}
	new->next = p->next;
	p->next = new;
	return 0;
}
int dellinklistbypos(linklist *head,int pos)
{
	if(head == NULL)
		return -1;
	if(pos < 0 || pos > getlinklistlength(head) - 1)
		return -1;
	linklist *p = head;
	while(pos--)
	{
		p = p->next;
	}
	linklist *q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	return 0;
}
int dellinklistbydata(linklist *head,data_t data)
{
	if(head==NULL)
		return -1;
	linklist *p=head;
	while(p->next!=NULL)
	{
		if(p->next->data == data)
			break;
		p=p->next;
	}
	if(p->next == NULL)
		return -1;//没有找到
	linklist *q=p->next;//P保存要删除结点的前一个结点
	p->next = q->next;
	free(q);
	q=NULL;
	return 0;


}
data_t searchlinklistbypos(linklist *head,int pos)//按位置返回值
{
	if(head == NULL)
		return -1;
	if(pos < 0 || pos > getlinklistlength(head) - 1)
		return -1;
	linklist *p = head->next;
	while(pos--)
	{
		p = p->next;
	}
	return p->data;
}
int searchlinklistbydata(linklist *head,data_t data)//按值返回位置
{
	if(NULL == head)
		return -1;
	linklist *p=head->next;
	int pos=0;
	while(p->next != NULL)
	{
		if(p->data == data)
		{
			break;
		}
		pos++;
		p=p->next;
	}
	return pos;
}
int updatelinklistbypos(linklist *head,int pos,data_t data)//按位置更新
{
	if(head == NULL)
		return -1;
	if(pos < 0 || pos > getlinklistlength(head) - 1)
		return -1;
	linklist *p = head->next;
	while(pos--)
	{
		p = p->next;
	}
	p->data=data;
	return 0;

}
int updatelinklistbydata(linklist *head,data_t old,data_t new)//按值更新
{
	if(NULL == head)
		return -1;
	int pos=0;
	if(-1 == (pos=searchlinklistbydata(head,old)))
		return -1;
	updatelinklistbypos(head,new,pos);
#if 0
	linklist *p=head->next;
	int flag=0;
	while(p!=NULL)
	{
		if(p->data == old)
		{
			flag=1;
			break;
		}
		p=p->next;//p就为要找的结点
	}
	if(!flag)
		return -1;
	p->data=new;
#endif
	return 0;
}
int daozhilinklist(linklist *head)//头插法
{
	if(head == NULL)
		return -1;
	linklist *p = head->next;//第一个有效结点
	linklist *q ;//保存P的下一个结点，保证P可以移动

	head->next = NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=head->next;//P与后面的结点断开
		//将结点与头结点相连
		head->next=p;
		p=q;//找到下一个结点
	}
	return 0;
} 
int clearlinklist(linklist *head)
	//清空链表，与链表倒置类似--最后只剩头结点
{
	if(NULL==head)
		return -1;
	linklist *p,*q;
	p=head->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	head->next=NULL;
	return 0;
}
int destorylinklist(linklist **head)//摧毁链表
{
	if(NULL == head);
	clearlinklist(*head);
	free(*head);
	*head=NULL;
	return 0;
}

linklist * combin_linklist(linklist *head1,linklist *head2,linklist *newhead)//链表合并
{
	if(!head1 || !head2 || !newhead)
		return NULL;
	linklist *p,*q,*s;
	p=head1->next;
	q=head2->next;
	s=newhead->next;
	while(p && q)
	{
		if(p->data < q->data)
		{
			s = p;
			s=s->next;
			p=p->next;
		}
		else
		{
			s = q;
			s=s->next;
			q=q->next;
		}
	}
	if(p)
	{
		s=p;
	}
	if(q)
	{
		s=q;
	}
	return newhead;
}
