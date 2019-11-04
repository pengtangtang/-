/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：黄修远
*   创建日期：2019年08月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "seqlist.h"
int main()
{
	seqlist *sq = seqlist_create();
	if(sq == NULL)
		printf("error\n");
	int i = 0;
	for(; i < 10; i++)
	insert_seqlistbypos(sq,i,i);
	print_seqlist(sq);//遍历表
	del_seqlistbypos(sq,7);
	print_seqlist(sq);//遍历表
	int num=searchseqlistbypos(sq,3);
	printf("num=%d\n",num);
	int a=search_seqlistbydata(sq,4);
	printf("a=%d\n",a);

	updateseqlistbypos(sq,2,3);
	print_seqlist(sq);//遍历表
	updateseqlistbynewdata(sq,4,5);
	print_seqlist(sq);//遍历表
	del_seqlistbydata(sq,4);	
	print_seqlist(sq);//遍历表
	return 0;
}
