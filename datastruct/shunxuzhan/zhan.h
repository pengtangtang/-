/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：zhan.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _ZHAN_H
#define _ZHAN_H
#define SIZE 100
typedef int data_t;
typedef struct seqstact{
	data_t data[SIZE];
	int top;//栈顶的下标
}stack;
stack * createstack();//创建栈
int clearstack(stack *st);//清空战
int stack_is_empty(stack *st);//判断栈空
int stack_is_full(stack *st);//判断栈满
int pushstack(stack *st,data_t data);//入栈
data_t popstack(stack *st);//出栈
data_t gettopstack(stack *st);//得到栈顶元素
int printstack(stack *st);//遍历栈
#endif
