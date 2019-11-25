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

struct job{
	char name[50];
	double salary;
	int floor;
};

template <> void Swap<job>(job &j1,job &j2);

void Show(job &j)

int main()
{
	int i = 10;
	int j = 20;
	cout << "i = " << i << ",j = " << j << endl;

	Swap(i,j);
	cout << "i = " << i << ",j = " << j << endl;


	job sue = {"pengtt",2340000,9};
	job tang = {"tang",123000,8};

	cout << "before job swaping:\n";
	Show(sue);
	Show(tang);

	Swap(sue,tang);
	cout 
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
