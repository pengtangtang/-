/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：map.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <map>

int main()
{
	map<char,int> a;
	a.insert(map<char,int>::value_type('c',1));
	a.insert(map<char,int>::value_type('d',2));

	map<char,int>::iterator b = a.find('c');
	cout << b->second << endl;

	cout << a['d'] << endl;
	a.clear();

	return 0;
}
