/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：seqlist.c
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
//创建表
seqlist *seqlist_create()
{
	seqlist * sq = (seqlist *)malloc(sizeof(seqlist));
	if(sq == NULL)
	{
		return NULL;
	}
	sq->last = -1;
	memset(sq->data,0,sizeof(sq->data));
	return sq;
}
//清空表
int clear_seqlist(seqlist *sq)
{
	if(sq == NULL)
		return -1;
	sq->last = -1;
	return 0;
}
//求表中有效元素个数
int get_seqlength(seqlist * sq)
{
	if(sq == NULL)
		return -1;
	return sq->last+1;
}
//表是否为空
int seqlist_is_empty(seqlist *sq)
{
	if(sq == NULL)
		return -1;
	return sq->last == -1;
}
//表是否为满
int seqlist_is_full(seqlist *sq)
{
	if(sq == NULL)
		return -1;
	return sq->last == SIZE-1;
}
//按位置插入
int insert_seqlistbypos(seqlist *sq,data_t data,int pos)
{
	if(sq == NULL)
		return -1;
	 if(seqlist_is_full(sq) || pos < 0 || pos > get_seqlength(sq))
		 return -1;
	int m = sq->last;
	for(; m >= pos ;m--)
	{
		sq->data[m+1] = sq->data[m];
	}
	sq->data[pos] = data;
	sq->last++;
	return 0;
}
//按位置删除
int del_seqlistbypos(seqlist *sq,int pos)
{
	if(sq == NULL)
		return -1;
	 if(seqlist_is_empty(sq) || pos < 0 || pos > get_seqlength(sq))
		 return -1;
	 int i;
	 for(i = pos; i<=sq->last; i++)
	 {
	 	sq->data[i] = sq->data[i+1];
	 }
	 sq->last--;
	return 0;
}
//打印表
int print_seqlist(seqlist *sq)
{
	if(sq == NULL)
		return -1;
	//printf("%d\n",sq->last);
	int i = 0;
	for(; i <= sq->last; i++)
	{
		printf(" %d ",sq->data[i]);
	}
	printf("\n");
	return 0;
}
//按位置查找返回值
int searchseqlistbypos(seqlist *sq,int pos)
{

	
	if(sq == NULL)
		return -1;
	 if(seqlist_is_empty(sq) || pos < 0 || pos > get_seqlength(sq)-1)
		 //下标为长度-1
		 return -1;
	 return sq->data[pos];

}
//按值更新返回位置
int search_seqlistbydata(seqlist *sq,data_t data)
{
	
	if(sq == NULL)
		return -1;
	 if(seqlist_is_empty(sq))
		 return -1;
	 int i;
	 for(i=0;i<=sq->last;i++)
	 {
	 	if(sq->data[i]==data)
		{
			return i;
		}
	 }
	 return -1;
}
//按位置更新
int updateseqlistbypos(seqlist *sq,data_t data,int pos)
{
	if(sq == NULL)
		return -1;
	 if(seqlist_is_empty(sq) || pos < 0 || pos > get_seqlength(sq)-1)//下标为长度-1
		 return -1;
	 sq->data[pos]=data;
	 return 0;


}
//用新值更新旧值
int updateseqlistbynewdata(seqlist *sq,data_t old,data_t new)
{
	if(sq == NULL)
		return -1;
	 if(seqlist_is_empty(sq))
		 return -1;
/*
	int i;
	for(i=0;i <= sq->last;i++)
	{
		if(sq->data[i] == old)
		{
			sq->data[i]=new;
		}
	}*/
	 sq->data[search_seqlistbydata(sq,old)]=new;
	return 0;
}
//按值进行删除
int del_seqlistbydata(seqlist *sq,data_t data)
{
	if(NULL == sq)
		return -1;
	if(seqlist_is_empty(sq))
		return -1;
	int pos=search_seqlistbydata(sq,data);
	if(-1 == pos)
		return -1;
	del_seqlistbypos(seqlist *sq,int pos)
	/*int i=pos;
	for(;i<sq->last;i++)
	{
		sq->data[i]=sq->data[i+1];
	}
	sq->last--;*/
	return 0;

}
