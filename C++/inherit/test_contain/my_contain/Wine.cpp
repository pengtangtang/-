/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：Wine.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Wine.h"

Wine::Wine():label("none"),pr(),years(0)
{}

Wine::Wine(const char* l,int y,const int yr[],const int bot[])
{
	label = l;
	years = y;
	ArrayInt a(yr,y);
	ArrayInt b(bot,y);
	pr = PairArray(a,b);
}

Wine::Wine(const char* l,int y)
{
	label = l;
	years = y;
	pr = PairArray();
}

void Wine::GetBottles()
{
	ArrayInt yr(years);
	ArrayInt bot(years);
	cout << "enter " << label << " data for" << years << " years\n";
	for(int i = 0;i < years;i++)
	{
		cout << "enter year: ";
		cin >> yr[i];
		cout << "enter bottles for that years: ";
		cin >> bot[i];
	}
	pr = PairArray(yr,bot);
}

void Wine::Show() const
{
	cout << "Wine: " << label << endl
		<<"\tyear\t" << "bottles\n";
	for(int i = 0;i < years;i++)
	{
		cout << "\t" << (pr.first())[i] << "\t"
			<< (pr.second())[i] << "\t\n";
	}
}

int Wine::Sum() const
{
	int s = 0;
	for(int i = 0;i < years;i++)
		s += (pr.second())[i];

	return s;
}
