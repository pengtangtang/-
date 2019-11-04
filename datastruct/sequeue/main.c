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
#include "sequeue.h"

int main()
{
	sequeue *sq=create_sequeue();
	int i;
	for(i=0;i<5;i++)
	{
		inqueue(sq,i);//入队 
	}
	print_queue(sq);
	data_t a=outqueue(sq);
	printf("a=%d\n",a);
	print_queue(sq);
	return 0;
}
