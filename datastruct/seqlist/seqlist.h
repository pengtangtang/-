/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：seqlist.h
*   创 建 者：黄修远
*   创建日期：2019年08月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _SEQLIST_H
#define _SEQLIST_H
#define SIZE 100 // 顺序表存储数据的空间长度100
typedef int data_t;//表中存储数据的数据类型；
typedef struct seq{
	data_t data[SIZE];
	int last;
}seqlist;
seqlist *seqlist_create();// 创建顺序表
int clear_seqlist(seqlist *sq);//清空表
int get_seqlength(seqlist * sq);// 求表中有效元素的个数
int seqlist_is_empty(seqlist *sq);//表是否为空
int seqlist_is_full(seqlist *sq);//表是否为满
int insert_seqlistbypos(seqlist *sq,data_t data,int pos); //按位置进行插入
int del_seqlistbypos(seqlist *sq,int pos);//按位置删除
int searchseqlistbypos(seqlist *sq,int pos);//按位置查找 返回的是表中的值
int search_seqlistbydata(seqlist *sq,data_t data);//按值查找，返回位置
int updateseqlistbypos(seqlist *sq,data_t data,int pos);//按位置更新值
int updateseqlistbynewdata(seqlist *sq,data_t old,data_t new);// 用新值更新旧值
int print_seqlist(seqlist *sq);//遍历表

#endif
