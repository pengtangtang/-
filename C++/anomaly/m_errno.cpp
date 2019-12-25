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
#include <cfloat>


bool hmean(double a,double b,double* ans);

int main()
{
	double x,y,z;

	cout << "Enter two numbers:";
	
	while(cin >> x >> y)
	{
		if(hmean(x,y,&z))
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
		else
		{
			cout << "One value should be negative .the errno is " << z
				<< endl;
			cout << "Enter next set of numbers (q to quit):";
		}
	}

	cout << "Buy!\n";
	return 0;
}

bool hmean(double a,double b,double* ans)
{
	if(a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}

	*ans =  2.0*a*b/(a+b);
	return true;
}
