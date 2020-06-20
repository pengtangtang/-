/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：array_class.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Size = 5;

template <class T>
class Array{
	private:
		T a[Size];
	public:
		Array(){
			for (int i = 0;i < Size;i++)
				a[i] = 0;
		}
		T& operator[](int i);
		void Sort();
};

template <class T>
T& Array<T>::operator[](int i)
{
	if(i < 0 || i > Size-1)
	{
		cout << "\ni error\n";
		exit(1);
	}
	return a[i];
}
template <class T>
void Array<T>::Sort()
{
	int p;
	for (int i = 0;i < Size-1;i++)
	{
		p = i;
		for (int j = i;j < Size;j++)
		{
			if (a[p] < a[j])
				p = j;
		}
		T t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}

template<> void Array<char *>::Sort()
{
	int p;
	for (int i = 0;i <Size;i++)
	{
		p = i;
		for (int j = i+1;j < Size;j++)
		{
			if(strcmp(a[p],a[j]) < 0)
				p = j;
		}
		char *t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}

int main()
{
	Array<int> a1;
	Array<char *> b1;

	a1.Sort();
	for (int i = 0;i <Size;i++)
		cout << '\t' << a1[i] << '\t' ;
	cout << endl;

	b1[0] = "x0";
	b1[1] = "x1";
	b1[2] = "x2";
	b1[3] = "x3";
	b1[4] = "x4";
	b1.Sort();
	for (int i = 0;i < Size;i++)
		cout << b1[i] << '\t' ;
	cout << endl;
}
