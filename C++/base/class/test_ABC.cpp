/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test_public.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "ABC.h"
const int CLIENTS = 4;

int main()
{
#if 1
	//虚方法测试,一个数组表示多种类型的对象
	AccABC * p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i = 0;i < CLIENTS;i++)
	{
		cout << "Enter client's name:";
		getline(cin,temp);
		cout << "Ente client's account number:";
		cin >> tempnum;
		cout << "ENter opening balance:$";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or " << "2 for BrassPlus Account:";

		while(cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2:";
		if(kind == '1')
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		else
		{
			double tmax,trate;
			cout << "Enter the overdraft limit:$";
			cin >> tmax;
			cout << "ENter the interest rate " << "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0;i < CLIENTS;i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for(int i = 0;i < CLIENTS;i++)
	{
		delete p_clients[i];
	}

	cout << "Done\n";
#else
	//基本方法测试
	Brass Piggy("Procelot Pigg",381299,4000.00);
	BrassPlus Hoggy("Horatio Hogg",382288,3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hoggy Account:\n";
	Hoggy.Desposit(1000.00);
	cout << "New balance:$" << Hoggy.Balance() << endl;
	cout << "Withrawing $4200 from Piggg Account:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg account balance :$ " << Piggy.Balance() << endl;
	cout << "WIthdrawing $4200 from the HOgg Account:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
#endif
	return 0;
}
