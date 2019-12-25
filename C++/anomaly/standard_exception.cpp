/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：standard_exception.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
//注意：若函数引发异常，却没有try块或对应的异常处理程序，程序最终调用abort()函数2
double hmean(double a,double b);

int main()
{
	double x,y,z;

	cout << "Enter two numbers:";

	while(cin >> x >> y)
	{
		try{//检查异常
			z = hmean(x,y);
		}catch(const char* s)//捕获异常
		{
			cout << s << endl;
			cout << "Enter a new pair of number:";
			continue;
		}

		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z  << endl;
		cout << "enter next set of number(q to quit):";
	}

	cout << "Buy!\n";
	return 0;
}

double hmean(double a ,double b)
{
	if(a == -b)//抛出异常
		throw "Bad hmean() argument : a = -b not allowed";
	return 2.0*a*b/(a+b);
}
