/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：bracket_stack.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Stack.h"
#include "string.h"

/*栈应用---括号匹配
 *
 * 描述：任意输入一组括号，可以判断括号是否匹配
 * 字符串实例：[()] [()()] [()[()]] [[()]*/

int main()
{
	Stack<char>* pStack = new Stack<char>(10);//存放扫描到的字符并且没有匹配到的情况
	Stack<char>* pStackNeed = new Stack<char>(10);//存放当前急需用来匹配的字符

	char str[] = "[()]";
	char currentNeed = 0;

	for(int i = 0;i < strlen(str);i++)
	{
		if(str[i] != currentNeed)
		{
			pStack->push(str[i]);
			switch(str[i])
			{
				case '[':
					if(currentNeed != 0)
					{
						pStackNeed->push(currentNeed);
					}
					currentNeed = ']';
					break;
				case('('):
					if(currentNeed != 0)
					{
						pStackNeed->push(currentNeed);
					}
					currentNeed = ')';
					break;
				default:
					cout << "字符串括号匹配\n";
					return 0;
			}
		}
		else
		{
			char elem;
			pStack->pop(elem);
			if(pStackNeed->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}

	if(pStack->stackEmpty())
	{
		cout << "括号匹配\n";
	}
	else
	{
		cout << "字符串括号不匹配\n";
	}
	delete pStack;
	delete pStackNeed;
	pStack = NULL;
	pStackNeed = NULL;

	return 0;
}
