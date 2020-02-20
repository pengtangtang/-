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
#include "Coordinate.h"


/*栈类：
 * 类模板：
 * 要求：
 *	将普通栈改造为类模板栈，使其可以适用于任何数据
 * 目的：灵活掌握栈机制，理解抽象数据类型在栈中应用
 */
int main()
{
#if 0
	Stack<Coordinate>* pStack = new Stack<Coordinate>(5);
	if(pStack->stackEmpty())
	{
		cout << "empty\n";
	}

	pStack->push(Coordinate(1,2));
	pStack->push(Coordinate(3,4));
	pStack->push(Coordinate(5,6));
	pStack->push(Coordinate(7,8));
	pStack->push(Coordinate(9,0));
#else

	Stack<char>* pStack = new Stack<char>(5);
	if(pStack->stackEmpty())
	{
		cout << "empty\n";
	}

	pStack->push('a');
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e');
#endif
	if(pStack->stackFull())
	{
		cout << "full\n";
	}
	
	pStack->stackTraverse(1);
	char e;
	pStack->pop(e);
	cout << e << endl;
	cout << pStack->stackLength() << endl;
	pStack->clearStack();


	cout << pStack->stackLength() << endl;


	delete pStack;
	pStack = NULL;
	return  0;
}
