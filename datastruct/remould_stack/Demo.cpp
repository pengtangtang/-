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
 * 1:定义Coordinate坐标类
 * 2：改造栈类，使其可以适用与坐标类
 *
 * 目的：灵活掌握栈机制，理解抽象数据类型在栈中应用
 */
int main()
{
	Stack* pStack = new Stack(5);
	if(pStack->stackEmpty())
	{
		cout << "empty\n";
	}

	pStack->push(Coordinate(1,2));
	pStack->push(Coordinate(3,4));
	pStack->push(Coordinate(5,6));
	pStack->push(Coordinate(7,8));
	pStack->push(Coordinate(9,0));
	if(pStack->stackFull())
	{
		cout << "full\n";
	}
	
	pStack->stackTraverse(1);
	pStack->clearStack();


	cout << pStack->stackLength() << endl;

	Coordinate e;
	pStack->pop(e);

	cout << e ;
	delete pStack;
	pStack = NULL;
	return  0;
}
