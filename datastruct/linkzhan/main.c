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
#include "linkstack.h"

int main()
{
	lstack *top=createlstack();
	int i;
	for(i=0;i<10;i++)
	{
		pushlstack(top,i);
	}
	print(top);
	data_t n=poplstack(top);
	printf("n=%d\n",n);
	print(top);
	pushlstack(top,19);
	print(top);
	int m=lstack_is_empty(top);
	printf("m=%d\n",m);
	return 0;
}
