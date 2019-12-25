/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：m_abort.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>


double hmean(double a,double b);

int main()
{
	double x,y,z;

	cout << "Enter two numbers:";
	
	while(cin >> x >> y)
	{
		z = hmean(x,y);
		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		cout << "Enter next set of numbers (q to quit):";
	}

	cout << "Buy!\n";
	return 0;
}

double hmean(double a,double b)
{
	if(a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		abort();
	}

	return 2.0*a*b/(a+b);
}
