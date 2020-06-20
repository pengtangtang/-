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
#include <string>
#include "public.h"

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f,precis p);

Brass::Brass(const string& s,long an,double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Desposit(double amt)//贷款
{
	if(amt < 0)
		cout << "Negative deposit not allowed;"
			<< "deposit is cancelled;\n";
	else
		balance += amt;
}

//取钱
void Brass::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if(amt < 0)
		cout << "Withdrawl amount must be positive;"
			<< "withdraw canceled;\n";
	else if(amt <= balance)
		balance -= amt;
	else
		cout << "withdrawl amount of $ " << amt << " exceeds your balance.\n"
			<< "withdrawal canceled.\n";
	restore(initialState,prec);
}

//账户剩余数
double Brass::Balance() const 
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "CLient: " << fullName << endl;
	cout << "Account Number:" << acctNum << endl;
	cout << "Balance:$" << balance << endl;
	restore(initialState,prec);
}

BrassPlus::BrassPlus(const string & s,long an,double bal,double ml,double r):Brass(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba,double ml,double r):Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum loan:$" << maxLoan << endl;
	cout << "Owed to bank:$" << owesBank << endl;
	cout.precision(3);
	cout << "Loan to bank:$" << 100*rate << "%\n";
	restore(initialState,prec);
}

void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance:$" << advance << endl;
		cout << "Finance charge :$" << advance * rate << endl;
		Desposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded.Transaction cancelled.\n";
	restore(initialState,prec);
}

format setFormat()
{
	return cout.setf(ios_base::fixed,ios_base::floatfield);//将浮点值的输出为定点，即包含两位小数
}

void restore(format f,precis p)
{
	cout.setf(f,ios_base::floatfield);
	cout.precision(p);
}
