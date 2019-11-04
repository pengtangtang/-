/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：dou_hao.c
*   创 建 者：pengtangtang
*   创建日期：2019年10月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
	char *a = "hello";
	char *b = "hello";
	char *c = "hello word";
	if(a==b)
		printf("a==b\n");
	if(a==c)
		printf("a==c\n");
	else
		printf("a!=c\n");
	return 0;
}
