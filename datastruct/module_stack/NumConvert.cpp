/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：NumConvert.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月16日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Stack.h"
#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16
/*栈应用：数值转换
 * 描述：输入任意的十进制N分别输出N的二进制、八进制、十六进制的数
 * 公式：N = （N div d）*d+N mod d
 * 目的：通过实例灵活掌握栈机制*/

int main()
{
	char num[] = "0123456789ABCEDF"; 
	Stack<int>* stack = new Stack<int>(30);

	cout << "please input a int number:";
	int N ;
	cin >> N;
	int N1 = N;
	int N2 = N;

	int mod = 0;
	int mod1 = 0;
	int mod2 = 0;
	
	while(N != 0)
	{
		mod = N%BINARY;
		stack->push(mod);
		N /= BINARY;
	}
	stack->stackTraverse(false);
	stack->clearStack();
	while(N2 != 0)
	{
		mod = N2%HEXADECIMAL;
		stack->push(mod);
		N2 /= HEXADECIMAL;
	}
#if 0 
	for(int i = stack->stackLength()-1;i >= 0;i--)
	{
		cout << num[stack[i]] << " ";
	}
	cout << endl;
#else
	int elem = 0;
	while(!stack->stackEmpty())
	{
		stack->pop(elem);
		cout << num[elem] << " ";
	}
	cout << endl;
#endif
	stack->clearStack();
	while(N1 != 0)
	{
		mod = N1%OCTONARY;
		stack->push(mod);
		N1 /= OCTONARY;
	}
	stack->stackTraverse(false);
	stack->clearStack();

	delete stack;
	stack = NULL;
	return 0;
}
