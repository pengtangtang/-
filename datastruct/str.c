/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：str.c
*   创 建 者：pengtangtang
*   创建日期：2019年10月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
void main()
{
	int c = 0xAD78;
	int a,b;

	printf("%#x\n",a);
	printf("%#x\n",b);
	int m,n;
	m = a >> 4;
	n = a << 4;
	m = m&0x000f;
	a = m|n;
	m = b >> 4;
	n = b << 4;
	m = m&0x000f;
	b = m|n;
	printf("%#x\n",c);
}

