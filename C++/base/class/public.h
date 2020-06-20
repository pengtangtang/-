/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：public.h
*   创 建 者：pengtangtang
*   创建日期：2020年04月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _PUBLIC_H
#define _PUBLIC_H

#include <string>

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nulbody",long an = 1,double bal = 0.0);
	void Desposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};


class BrassPlus:public Brass
{
	private:
		double maxLoan;
		double rate;
		double owesBank;
	public:
		BrassPlus(const std::string& s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.11125);
		BrassPlus(const Brass& ba,double ml = 500,double r = 0.11125);
		virtual void ViewAcct() const;
		virtual void Withdraw(double amt);
		void ReaseMax(double m ) {maxLoan = m;}
		void ReaseRate(double r) {rate = r; }
		void ReaseOwes() { owesBank = 0; }
};

#endif

