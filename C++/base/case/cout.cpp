/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：cout.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
	char c[30] = "this is string";
	double d = -1231.23;
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::left);
	cout << c << "--------------L1" << endl;
	cout.width(30);
	cout.fill('-');
	cout.setf(ios::right);
	cout << c << "--------------L2" << endl;

	cout.setf(ios::dec | ios::showbase | ios::showpoint);
	cout.width(30);
	cout << d << "-------------	L3" << endl;
	cout.setf(ios::showpoint);
	cout.precision(10);
	cout.width(30);
	cout << d << "-------------L4" << endl;
	cout.width(30);
	cout.setf(ios::oct,ios::basefield);
	cout << 100 << "------------L5" << endl;
	return 0;
}
