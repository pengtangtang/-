/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：pair.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <utility>
#include <string>

typedef pair<string,string> su;

int main()
{
	int flag;
	string x1,x2;
	pair<string,string> p1("a","cd");
	su p2("a","dre");
	su p3;
	string name;

	name = p1.second;
	cout << p1.first << endl;
	cout << name << endl;
	
	flag = p1<p2;
	cout << flag << endl;

	flag = p1>p2;
	cout << flag << endl;

	while (cin >> x1 >> x2)
	{
		p3 = make_pair(x1,x2);
		cout << p3.first << endl << p3.second << endl;
	}

	return 0;
}
