/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：digui.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int f(int n);

int main()
{
	cout << "input x:";
	int x;
	cin >> x;
	cout << f(x) << endl;

	return 0;
}

int f(int x)
{
	if (0 == x)
		return 1;
	else
		return x*f(x-1);
}
