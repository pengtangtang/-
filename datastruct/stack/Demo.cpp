/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Stack.h"


/*栈类：
 * 要求：
 * Stack(int size);
 * ~Stack();
 * bool stackEmpty();
 * bool stackFull();
 * void clearStack();
 * int stackLength();
 * void push(char elem);
 * char pop(char& elem);
 * void stackTraverse();
 *
 * 目的：掌握栈的实现原理和运行机制*/


int main()
{
	Stack* pStack = new Stack(5);
	if(pStack->stackEmpty())
	{
		cout << "empty\n";
	}

	pStack->push('A');
	pStack->push('A');
	pStack->push('A');
	pStack->push('A');
	pStack->push('A');
	if(pStack->stackFull())
	{
		cout << "full\n";
	}
	
	pStack->stackTraverse(1);
	pStack->clearStack();


	cout << pStack->stackLength() << endl;

	char e = 0;
	pStack->pop(e);
	cout << "e = " << e << endl;

	delete pStack;
	pStack = NULL;
	return  0;
}
