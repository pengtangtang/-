/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：4.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>

int main()
{
#if 0

#else
	cout << "What is your first name? ";
	string name;
	cin >> name;

	cout << "What is your last name? ";
	string lname;
	cin >> lname;
	lname += ','+name;

	cout << "What letter grade dou you deserve?";
	char ch;
	cin >> ch;

	cout << "WHat is your age？";
	int age;
	cin >> age;

	cout  << "Nmae:" << lname << endl;
	cout << "Grade:" << ++ch << endl;
	cout << "Age:" << age << endl;
#endif
	return 0;
}
