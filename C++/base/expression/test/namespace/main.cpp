/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：main.cpp
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

void other(void);
void another(void);

int main()
{
	using debts::Debt;
	using debts::showDebt;
	Debt golf = {{"Benny","Goatsbiff"},120.0};
	showDebt(golf);
	other();
	another();
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;

	Person dg = {"Doodles","Glister"};
	showPerson(dg);
	cout << endl;
	Debt zippy[3];

	int i;
	for(i = 0;i < 3;i++)
	{
		getDebt(zippy[i]);
	}

	for(i = 0;i < 3;i++)
	{
		showDebt(zippy[i]);
	}

	cout << "Total debt : $" << sumDebt(zippy,3) << endl;

	return ;
}

void another(void)
{
	using pers::Person;
	Person collector = {"Milo","Right"};
	pers::showPerson(collector);
	std::cout << std::endl;
}
