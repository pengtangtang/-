/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：ptr_static.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _PTR_STATIC_H
#define _PTR_STATIC_H

template<class Type>
class Stack{
	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack & st);
		~Stack() {delete [] items;}
		bool isempty() {return 0==top;}
		bool isfull() {return stacksize==top;}
		bool push(const Type &item);
		bool pop(Type &item);
		Stack& operator = (const Stack &st);
	private:
		enum {SIZE = 10};
		int stacksize;
		Type *items;
		int top;
};

/*原型将赋值运算符函数的返回类型声明为Stack引用,而实际的模板函数定义将类型定义为Stack<Type>
 * 住：可以在模板声明或模板函数定义内使用Stack，但在类外面，即指定返回类型或使用作用域解析运算符时，必须使用完整的Stack<Type>*/
template<class Type>
Stack<Type>& Stack<Type>::operator = (const Stack &st)
{
	if(this == &st)
		return *this;
	delete [] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for(int i=0;i<stacksize;i++)
		items[i] = st.items[i];
	return *this;
}

template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0)
{
	items = new Type[stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for(int i=0;i<stacksize;i++)
		items[i] = st.items[i];
}
template<class Type>
bool Stack<Type>::push(const Type &item)
{
	if(top < stacksize)
	{
		items[top++] = item;
		return true;
	}
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
