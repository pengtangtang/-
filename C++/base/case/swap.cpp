/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：swap.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

void swap(int &a,int &b);

int main()
{
	int x1(5);
	int x2(7);

	swap(x1,x2);
	cout << x1 << " " << x2 << endl;
	return 0;
}

void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}
