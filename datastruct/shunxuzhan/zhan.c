/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：zhan.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "zhan.h"
stack *createstack()//创建栈
{
	stack *st=(stack *)malloc(sizeof(stack));
	if(st == NULL)
		return NULL;
	st->top=-1;//表空不指向任何元素
	memset(st->data,0,sizeof(st->data));//初始
	return st;
}
int clearstack(stack *st)//清空栈
{
	if(st == NULL)
		return -1;
	st->top = -1;
	return 0;
}
int stack_is_empty(stack *st)//栈是否为空
{
	if(st == NULL)
		return -1;
	return st->top==-1;
}
int stack_is_full(stack *st)//栈是否为满
{
	if(st == NULL)
		return -1;
	return st->top == SIZE-1;
}
int pushstack(stack *st,data_t data)//入栈
{
	if((st == NULL) || stack_is_full(st))
	//判断栈是否满
		return -1;
	st->data[st->top+1] = data;
	st->top++;
	return 0;
}
data_t popstack(stack *st)//出栈
{
	if((st == NULL) || stack_is_empty(st)) 
		return -1;
	data_t data=st->data[st->top];
	st->top--;
	return data;
}
data_t gettopstack(stack *st)
{
	if((st == NULL) || stack_is_empty(st)) 
		return -1;
	data_t data=st->data[st->top];
	return data;
}
int  printstack(stack *st)
{
	if((st == NULL) || stack_is_empty(st)) 
		return -1;
	int i=st->top;
	while(i>=0)
	{
		printf("%-2d",st->data[i]);
		i--;
	}
	printf("\n");
	return 0;
}
