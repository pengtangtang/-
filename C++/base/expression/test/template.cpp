/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：template.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

template <typename T>
void Swap(T &a,T &b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

template <> void Swap<job>(job &j1,job &j2);
void Show(job &);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i = 10,j = 20;

	cout << "i = " << i << "j = " << j << '\n';
	Swap(i,j);
	cout << "i = " << i << "j = " << j << '\n';

	job sue = {"Susan Yafffee",7300.60,7};
	job sidney = {"Sidney",78060.72,9};

	cout << "Befor swap:\n";
	Show(sue);
	Show(sidney);

	Swap(sue,sidney);
	Show(sue);
	Show(sidney);
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

template <> void Swap<job>(job &j1,job &j2)
{
	double t1;
	int t2;

	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job &j)
{
	cout << j.name << ": $ " << j.salary << " : on floor " << j.floor << endl;
}
