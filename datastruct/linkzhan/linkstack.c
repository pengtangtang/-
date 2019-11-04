/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linkstack.c
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
#include "linkstack.h"

lstack *createlstack()
{
	lstack *top=(lstack *)malloc(sizeof(lstack));
	if(top==NULL)
		return NULL;
	top->data=-1;
	top->next=NULL;
	return top;
}
int pushlstack(lstack *top,data_t data)
{
	if(NULL == top)
		return -1;
	lstack *new=(lstack *)malloc(sizeof(lstack));
	if(NULL == new)
		return -1;
	new->data=data;
	new->next=NULL;

	new->next=top->next;
	top->next=new;
	return 0;
}
int lstack_is_empty(lstack *top)
{
	if(NULL == top)
		return -1;
	return top->next == NULL;	
}
data_t poplstack(lstack *top)
{
	if((NULL == top) || lstack_is_empty(top))
		return -1;
	lstack *p=top->next;//指向被删除的结点
	data_t data= p->data;
	top->next=p->next;//将头结点与被删除的下一结点
	free(p);
	p=NULL;
	return data;
}
int print(lstack *top)
{
	if((NULL == top) || lstack_is_empty(top)) 
		return -1;
	lstack *p=top->next;//第一个有效结点
	while(p)
	{
		printf("%-3d",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
