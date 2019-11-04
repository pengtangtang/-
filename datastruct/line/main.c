/*===============================================================
 *   Copyright (C) 2019 All rights reserved.
 *   
 *   文件名称：main.c
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

int main()
{
	linklist *head1 = createlinklist();
	linklist *head2 = createlinklist();
	linklist *newhead = createlinklist();
	int i;
	for(i=0;i<5;i++)
	{
		insertlinklistbypos(head1,i,i);
	}
	for(i=0;i<8;i++)
	{
		insertlinklistbypos(head2,i,i);
	}
	linklist *combine_linklist(linklist *head1,linklist *head2,linklist *newhead);//将两个有序链表合并
	print_linklist(newhead);

/*	linklist *head = createlinklist(); 
	int i = 0;
	for(i = 0; i < 10;i++)
	{
		insertlinklistbypos(head,i,i);
	}
	insertlinklistbypos(head,12,0);
	insertlinklistbypos(head,67,5);
	print_linklist(head);
	dellinklistbypos(head,3);
	dellinklistbypos(head,10);
	print_linklist(head);
	dellinklistbydata(head,2);
	print_linklist(head);
	data_t n=searchlinklistbypos(head,1);
	printf("n=%d\n",n);
	int m=searchlinklistbydata(head,4);
	printf("m=%d\n",m);
	updatelinklistbypos(head,3,5);
	print_linklist(head);
	updatelinklistbypos(head,3,78);
	print_linklist(head);
	daozhilinklist(head);
	print_linklist(head);
	clearlinklist(head);
	print_linklist(head);
	destorylinklist(&head);//摧毁链表即头结点所占空间*/


	return 0;
}
