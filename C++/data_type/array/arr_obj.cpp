/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：arr_obj.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <array>

const int Seasons = 4;
const array<string,Seasons> Snames = 
{"Spring","Summer","Fail","Winter"};
#if 0
/*原来版本*/
void fill(array<double,Seasons> *pa);

void show(array<double,Seasons> da);

int main()
{
	array<double,Seasons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(array<double,Seasons> *pa)
{
	cout << "fill start\n";
	for(int i = 0;i<Seasons; i++)
	{
		cout << "enter " << Snames[i] << " expenses:";
		cin >> (*pa)[i];
	}
	cout << "fill end\n";
}

void show(array<double,Seasons> da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i=0; i<Seasons;i++)
	{
		cout << Snames[i] << ":$" << da[i] << endl;
		total += da[i];
	}
	cout << "total expenses:$ " << total << endl;
}
#else
/*使用引用的改良版本*/
void fill(array<double,Seasons> &pa);

void show(array<double,Seasons> &da);

int main()
{
	array<double,Seasons> expenses;
	fill(expenses);
	show(expenses);
	return 0;
}

void fill(array<double,Seasons> &pa)
{
	cout << "fill start\n";
	for(int i = 0;i<Seasons; i++)
	{
		cout << "enter " << Snames[i] << " expenses:";
		cin >> pa[i];
	}
	cout << "fill end\n";
}

void show(array<double,Seasons> &da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i=0; i<Seasons;i++)
	{
		cout << Snames[i] << ":$" << da[i] << endl;
		total += da[i];
	}
	cout << "total expenses:$ " << total << endl;
}
#endif
