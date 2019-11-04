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
#include "zhan.h"

int main()
{
	stack *st=createstack();
	int i=0;
	for(i=0;i<10;i++)
	{
		pushstack(st,i);
	}
	printstack(st);
	data_t a=popstack(st);
	printf("a=%d\n",a);
	printstack(st);
	return 0;
}
