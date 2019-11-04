/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
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

int main()
{
	dlinklist *head=createdlinklist();
	int i;
	for(i=0;i<10;i++)
	{
		insertdlinklistbypos(head,i,i);
	}
	print_dlinklist(head);
	del_dlinklist(head,2);
	print_dlinklist(head);
	int a=get_lengthdlinklist(head);
	printf("a=%d\n",a);
	if(insertdlinklistbypos(head,2,12))//判断是否插入成功
		printf("insert error!\n");
	return 0;
}

