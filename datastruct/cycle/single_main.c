/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：ini.c
*   创 建 者：liujing
*   创建日期：2019年08月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
//单向循环链表初始化

typedef struct clinklist
{
	int data;
	struct clinklist *next;
}node;

void ini(node *pnode)
{
	int item;
	node *target;
	node *tem;
	printf("input your number,input 0 is over:");

	while(1)
	{
		scanf("%d",&item);
		fflush(stdin);//情空缓冲区
		if(0==item)
			return ;
		if(pnode==NULL)
		{
			pnode = (node *)malloc(sizeof(struct clinklist));
			if(!pnode)//判断空间是否申请成功
				exit(0);
			pnode->data=item;
			pnode->next=pnode;
		}
		else
		{
			for(target=pnode;target->next!=pnode;target=target->next);
			tem=(node *)malloc(sizeof(struct clinklist));
			if(!tem)
				exit(0);
			tem->data=item;
			tem->next=pnode;
			target->next=tem;
		}
	}
}

void reverse(node *pnode)
{
	if(NULL == pnode)
		exit(0);
	node *target;
	for(target=pnode;target->next!=pnode;target=target->next)
	{
		printf("%-4d",target->data);
	}
	printf("\n");
}

int main()
{
	node *pnode=NULL;
/*
	char num;
	printf("链表基本程序：\n1：初始化链表\n2:遍历链表\n3：插入元素\n4:删除元素\n#：退出程序\n");
	while(1)
	{
		scanf("%c",&num);
		if('#' == num)
		{
			break;
		}
		int d;
		switch(num)
		{
			case 1:
				ini(pnode);
				break;
			case 2:
		//		reverse(pnode);
				break;
			case 3:
				printf("input the weizi:");
		//		scanf("%d",&d);
		//		insert(pnode,d);
				break;
			case 4:
		//		printf("input the del number:");
		//		scanf("%d",d);
		//		del(pnode,d);
				break;
			default:
				num='#';
				break;
		}
	}
	
*/
	ini(pnode);
	reverse(pnode);
	return 0;
}
