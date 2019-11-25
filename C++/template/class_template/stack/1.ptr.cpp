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
	Stack<char *> st;
	char ch;
	char* po;

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
