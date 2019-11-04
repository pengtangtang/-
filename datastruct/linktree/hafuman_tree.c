/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：hafuman_tree.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

unsigned char bit_reverse(unsigned char c)
{
	unsigned char buf = 0;
	int bit = 8;
	while(bit){
		bit--;
		buf |= ((c&1) << bit);
		c >>= 1;
	}
	return buf;
}

int main()
{
	unsigned char c='0';
	printf("%d\n",bit_reverse(c));
return 0;
}
