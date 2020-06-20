/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：ABC.cpp
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

AccABC::AccABC(const string & s,long an,double bal )
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AccABC::Deposit(double amt)
{
	if(amt < 0)
		cout << "negative deposit not allowed;"
			<< "deposit is canceled;\n";
	else
		balance += amt;
}

void AccABC::Withdraw(double amt)
{
	balance -= amt;
}

AccABC::Formatting AccABC::SetFormat() const
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AccABC::Restore(Formating & f) const
{
	cout.setf(f.flag,ios_base::floatfield);
	cout.precision(f.pr);
}

void Brass::Withdraw(double amt) 
{
	if(amt < 0)
		cout << "Withdraw amount must be positive;"
			<< "withdraw canceled;\n";
	else if(amt <= Balance())
	{
		AccABC::Withdraw(amt);
	}
	else
		cout << "Withdraw amount of $" << amt << " execeds your balance.\n"
			<< "withdraw canceled\n";
}

void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass Client: " << FullName() << endl;
	cout << "Account Number:" << AcctNum() << endl;
	cout << "Blance:$" << Balance() << endl;
	Restore(f);
}

BrassPlus::BrassPlus(const string& s,long an,double bal,double ml,double r):AccABC(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const string& ba,double ml,double r):AccABC(ba)
{

	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Account Number:" << AcctNum() << endl;
	cout << "Blance:$" << Balance() << endl;
	cout << "MaxNUm loan :$" << maxLoan << endl;
	cout << "Owed to bank:$" << owesBank << endl;

	cout.precision(3);
	cout << "Loan to bank:$" << oweBank() << endl;
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();

	double bal = Balance();
	if (amt <= bal)
		AccABC::Withdraw(amt);
	else if( amt <= bal+maxLoan-owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance :$" << advance << endl;
		cout << "Finance charge:$" << advance*rate << endl;
		Deposit(advance);
		AccABC::Withdraw(mat);
	}
	else
		cout << "Gredit limit ecceeded.Transaction cancelled.\n";
	Restore(f);
}
