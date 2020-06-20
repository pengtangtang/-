/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：pi.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

double arctan(double x);


int main()
{
	double a = 16.0 * arctan(1.0/5.0);
	double b = 4.0 * arctan(1.0/239.0);
	double pi = a - b;
	cout << pi << endl;
	return 0;
}

double arctan(double x)
{
	double head = x;
	int tail = 1;
	double art = 0;

	while (double(head/tail) > 1e-15)
	{
		art = (tail%4==1)? art+head/tail:art-head/tail;
		head *= x*x;
		tail += 2;
		cout << "-----------\n";
		cout << tail << endl;
		cout << "-----------\n";
	}

	return art;
}
