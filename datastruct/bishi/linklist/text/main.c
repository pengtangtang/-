/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
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

int main()
{
/*	linklist *head = create_linklist();
	int i;
	for(i=0;i<2;i++)
	{
		insert_linklist(head,i,i);
	}
	display_linklist(head);

	if(insert_linklist(head,4,1) == -1)
	{
		printf("insert failed\n");
	}
	display_linklist(head);
	//delete_bypos_linklist(head,1);
//	delete_bydata_linklist(head,1);
//	clear_linklist(head);
//	destroy_linklist(&head);
//	display_linklist(head);
	
	convert_linklist(head);*/
	linklist *head1 = create_linklist();
	linklist *head2 = create_linklist();
	linklist *newhead = create_linklist();

	int i,j=0;
	for(i=0; i<4; i++)
		insert_linklist(head1,i,i);
	for(i=3; i<8; i++)
		insert_linklist(head2,i,j++);
	newhead = combine_linklist(head1,head2,newhead);
	
	display_linklist(head1);
	display_linklist(head2);
	display_linklist(newhead);
	return 0;
}
