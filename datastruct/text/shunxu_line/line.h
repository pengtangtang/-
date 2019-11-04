/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：line.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月06日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINE_H
#define _LINE_H

#define SIZE 10
typedef int data_t;
typedef struct node
{
	data_t data[SIZE];
	int last;
}seqlist;
seqlist *seqlist_create();
int ini_seqlist(seqlist *sq,data_t data,int pos);
int insert_seqlist(seqlist *sq,data_t data,int pos);
int print(seqlist *sq);
int del_seqlist(seqlist *sq,int pos);
#endif
