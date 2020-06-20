/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：namesp.h
*   创 建 者：pengtangtang
*   创建日期：2020年03月21日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _NAMESP_H
#define _NAMESP_H

#include <string>

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};

	void getPerson(Person &);
	void showPerson(const Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};

	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebt(const Debt ar[],int n);
}

#endif
