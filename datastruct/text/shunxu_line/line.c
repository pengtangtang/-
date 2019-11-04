/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：line.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月06日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "line.h"
seqlist * seqlist_create()
{
	seqlist *sq = (seqlist *)malloc(sizeof(seqlist));
	if(sq == NULL)
		exit(0);
	sq->last=-1;
	return sq;

}
int ini_seqlist(seqlist *sq,data_t data,int pos)
{
	if(sq == NULL)
		return -1;
	sq->data[pos]=data;
	sq->last++;
	return SIZE-(sq->last+1);
}
int insert_seqlist(seqlist *sq,data_t data,int pos)
{
	if(NULL == sq)
		return -1;
	if(pos<0 || pos>SIZE-1)
	{
		printf("your pose is illeagle!\n");
		return -1;
	}
	int i=sq->last;
	for(;i>=pos;i--)
	{
		sq->data[i+1]=sq->data[i];
	}
	sq->data[pos]=data;
	sq->last++;
	return 0;
}
int  print(seqlist *sq)
{
	if(NULL == sq)
		return -1;
	int i;
	for(i=0;i<=sq->last;i++)
	{
		printf("%-4d",sq->data[i]);
	}
	printf("\n");
	return SIZE-1-sq->last;
}
int del_seqlist(seqlist *sq,int pos)
{
	if(NULL == sq)
		return -1;
	if(pos<0 || pos>SIZE)
		return -1;
	int i=pos;
	for(;i<=sq->last;i++)
	{
		sq->data[i]=sq->data[i+1];
	}
	sq->last--;
	return 0;
}
