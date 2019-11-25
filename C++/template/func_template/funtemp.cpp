/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：funtemp.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
template <typename T>
void Swap(T &a,T &b);

int main()
{
	int i = 10;
	int j = 20;
	cout << "i = " << i << ",j = " << j << endl;

	Swap(i,j);
	cout << "i = " << i << ",j = " << j << endl;

	double x = 24.3;
	double y = 81.7;

	cout << "x = " << x << ", y = " << y << endl;
	Swap(x,y);
	cout << "x = " << x << ", y = " << y << endl;


	return 0;
}
template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
