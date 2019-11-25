/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：stack.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _STACK_H
#define _STACK_H

template<class Type>
class Stack{
	public:
		Stack();
		bool is_empty();
		bool is_full();
		bool push(const Type &item);
		bool pop(Type &item);
	private:
		enum {MAX = 10};
		Type items[MAX];
		int top;
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::is_empty()
{
	return 0==top;
}

template<class Type>
bool Stack<Type>::is_full()
{
	return MAX==top;
}

template<class Type>
bool Stack<Type>::push(const Type& item)
{
	if(MAX > top){
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
bool Stack<Type>::pop(Type &item)
{
	if(0 < top)
	{
		item = items[--top];
		return true;
	}
	else 
		return false;
}
#endif
