/*===============================================================
 *   Copyright (C) 2019 All rights reserved.
 *   
 *   文件名称：main.c
 *   创 建 者：pengtangtang
 *   创建日期：2019年08月08日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "linkqueue.h"

int main()
{
	lsequeue *lq=create_lsequeue();
	int i;
	for(i=0;i<5;i++)
	{
		in_lsequeue(lq,i);
	}
	
	print_lsequeue(lq);
	in_lsequeue(lq,9);
	print_lsequeue(lq);
	for(i=0;i<6;i++)
	{
		data_t data=out_lsequeue(lq);
		printf("data=%-2d\n",data);
	}
	return 0;
}
