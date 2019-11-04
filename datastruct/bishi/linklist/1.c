/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：1.c
*   创 建 者：pengtangtang
*   创建日期：2019年09月24日
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
#if 0
	char a[] = "hello";
	char *p,*q;
	p=q=a;
	while(*p)
		p++;
	p--;
	while(*p != *q){
		*p ^= *q;
		*q ^= *p;
		*p ^= *q;
		p--;
		q++;
	}
#else
	char *a = "hello";
	char *p = (char *)malloc(strlen(a)+1);
	char *q = p;
	while(*a)
		a++;
	while(*p++ = *--a);
	*p = '\0';

#endif
	printf("%s",q);
}
