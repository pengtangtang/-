/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：power.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
double power(double x,int n);


int main(int argc,char const *argv[])
{
	int x;
	cin >> x;
	int wei = 0;
	int sum = 0;
	int each,chu;

	for (int i = 0;i < 8;i++)
	{
		each = x % 10;
		chu = x / 10;
		sum += each * power(2,wei);
		x = chu;
		wei++;
	}

	cout << sum << endl;
	return 0;
}
double power(double x,int n)
{
	double val = 1.0;
	while (n--)
	{
		val *= x;
	}
	return val;
}
