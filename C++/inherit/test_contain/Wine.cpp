/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：Wine.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Wine.h"

Wine::Wine(const char *l,int y,const int yr[],const int bot[])
{
	lable = l;
	y_number = y;
	ArrayInt a(y);
	ArrayInt b(y);

	for(int i = 0;i < y;i++)
	{
		a[i] = yr[i];
		b[i] = bot[i];
	}

	MyWine = PairWine(a,b);

}

Wine::Wine(const char* l,int y)
{
	lable = l;
	y_number = y;

	ArrayInt a(y);
	ArrayInt b(y);

	MyWine = PairWine(a,b);
}

void Wine::GetBottles()
{
	cout << "enter " << lable << " data for " << y_number << " year(s):\n";

	for(int i = 0;i < y_number;i++)
	{
		cout << "enter year: ";
		cin >> MyWine.first[i];
		cout << "enter bottles for that year: ";
		cin >> MyWine.second[i];
	}
}

void Wine::Show() const
{
	cout << "Wine: " << lable << endl
		<< "\tYear\tBottles\n";
	for(int i = 0;i < y_number;i++)
	{
		cout << "\t" <<  MyWine.first[i] << "\t"
			<< MyWine.second[i] << "\t\n";
	}

}

const string& Wine::Lable()
{
	return lable;
}

int Wine::Sum()
{
	int num = 0;
	for(int i = 0;i < y_number;i++)
	{
		num += MyWine.second[i];
	}
	return num;
}

