/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linkstack.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINKSTACK_H
#define _LINKSTACK_H

typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}lstack;
lstack * createlstack();//创建栈
int pushlstack(lstack *top,data_t data);//入栈
data_t poplstack(lstack *top);//出栈
int lstack_is_empty(lstack *top);//判断栈是否为空
int print(lstack *top);//遍历栈
#endif
