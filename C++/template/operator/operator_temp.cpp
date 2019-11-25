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

template <typename T>
void Swap(T *a,T *b,int n);

void Show(int a[]);
const int Lim = 8;


int main()
{
	int i = 10;
	int j = 20;
	cout << "i = " << i << ",j = " << j << endl;

	Swap(i,j);
	cout << "i = " << i << ",j = " << j << endl;

	int d1[Lim] = {0,1,2,9,4,2,7,4};
	int d2[Lim] = {4,3,2,1,7,6,8,0};

	cout << "original arrays: \n";

	Show(d1);
	Show(d2);

	Swap(d1,d2,Lim);

	cout << "Swap arrays: \n";
	Show(d1);
	Show(d2);

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

template <typename T>
void Swap(T *a,T *b,int n)
{
	T temp;
	for(int i = 0;i < Lim;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	for(int i = 0;i < Lim ; i++)
		cout << a[i] << " ";
	cout << endl;
}
