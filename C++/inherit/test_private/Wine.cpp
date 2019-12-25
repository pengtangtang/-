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

Wine::Wine():string("none"),PairArray(),years(0)
{}

Wine::Wine(const char* l,int y,const int yr[],const int bot[]):string(l),years(y),PairArray(ArrayInt(yr,y),ArrayInt(bot,y))
{

}

Wine::Wine(const char* l,int y):string(l),years(y),PairArray()
{

}

void Wine::GetBottles()
{
	ArrayInt yr(years);
	ArrayInt bot(years);
	cout << "enter " << (const string&)*this << " data for" << years << "years:\n";

	for(int i = 0;i < years;i++)
	{
		cout << "enter year: ";
		cin >> yr[i];
		cout << "enter bottles for that year: ";
		cin >> bot[i];
	}
	PairArray::operator = (PairArray(yr,bot));
}

void Wine::Show() const
{
	cout << "wine: " << (const string&)*this << endl;
	cout << "\tyear\t" << "bottles\t\n";

	for(int i = 0;i < years;i++)
		cout << "\t" << (PairArray::first())[i] << "\t" << (PairArray::second())[i] << endl;
}

int Wine::Sum() const
{
	int s = 0;
	for(int i = 0;i < years;i++)
		s += (PairArray::second())[i];
}

