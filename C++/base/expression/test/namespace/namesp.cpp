/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：namesp.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月21日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;

	void getPerson(Person & rp)
	{
		cout << "Enter first name:";
		cin >> rp.fname;
		cout << "ENter last name:";
		cin >> rp.lname;
	}

	void showPerson(const Person & rp)
	{
		cout << rp.lname << "," << rp.fname << endl;
	}
}

namespace debts
{
	void getDebt(Debt & rd)
	{
		getPerson(rd.name);
		std::cout << "Enter debt:";
		std::cin >> rd.amount;
	}

	void showDebt(const Debt & rd)
	{
		showPerson(rd.name);
		std::cout << ":$" << rd.amount << std::endl;
	}

	double sumDebt(const Debt ar[],int n)
	{
		double total = 0;
		for(int i = 0;i < n;i++)
			total += ar[i].amount;

		return total;
	}
}
