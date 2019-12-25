/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：obj_exception.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "obj_exception.h"
#include <cmath>
double hmean(double a,double b);
double gmean(double a,double b);

int main()
{
	double x,y,z;

	cout << "Enter two numbers:";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers (q to quit):";
		}
		catch(bad_hmean& bg)
		{
			bg.mesg();
			cout << "try again\n";
			continue;
		}
		catch(bad_g_mean& hg)
		{
			cout << hg.mesg();
			cout << "Value used :" << hg.v1 << "," << hg.v2 << endl;
			cout << "Sory ,you don't get to play any more.\n";
			break;
		}
	}
	cout << "Buy!\n";

	return 0;
}

double hmean(double a,double b)
{
	if(a == b)
	{
		throw bad_hmean(a,b);
	}
	return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw bad_g_mean(a,b);
	return sqrt(a*b);
}
