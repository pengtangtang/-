/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：stack.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"

int main()
{
#if 1
	Stack<string> st;
	char ch;
	string po;
#else
	/*指针栈的错误使用*/
	//1：仅仅创建指针却没有为输入字符串创建空间来保存
	Stack<char *> st;
	char ch;
	char *po;
	//2：在pop（）时，不能将出队元素赋给数组名
	Stack<char *> st;
	char ch;
	char po[40];
	//3:po总是指向一个地址，并没有保存每一个新的字符串，而是覆盖了前一个值。
	Stack<char *> st;
	char ch;
	char *po = new char[40];
#endif

	cout << "please enter A to add a purchase order,\n"
		<< "P to process a po,or Q to quit\n";

	while(cin>>ch && toupper(ch)!='Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':cout << "enter a po number to add:";
				 cin >> po;
				 if(st.is_full())
					 cout << "static is already full\n";
				 else
					 st.push(po);
				 break;
			case 'P':
			case 'p':if(st.is_empty())
					 cout << "statck is already empty\n";
				 else
				 {
				 	st.pop(po);
					cout << "PO#" << po << "poped\n";
					break;
				 }
		}
	cout << "please enter A to add a purchase order,\n"
		<< "P to process a po,or Q to quit\n";
	}

	cout << "Buy\n";
	return 0;
}
