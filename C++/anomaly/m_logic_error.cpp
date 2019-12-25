/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：obj_exception.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
class bad_hmean : public logic_error
{
	public:
		explicit bad_hmean(const string& n = "hmean",const string& s = "error in hmean()",double a = 0,double b = 0);
		void mesg();
		const char* what() { return "bad arguments in hmean()\n"; }
		virtual ~bad_hmean() throw() {}
	private:
		string name;
		double v1;
		double v2;
};

//调用logic_error()
bad_hmean::bad_hmean(const string& n,const string& s,double a,double b):name(n),logic_error(s),v1(a),v2(b) {}
inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << "," << v2 << " )invalid arguments:a = -b\n";
}

class bad_gmean : public logic_error
{
	public:
		double v1;
		double v2;
		explicit bad_gmean(const string& n = "gmean",const string& s = "error in gmean()",double a = 0,double b = 0);
		const char* mesg();
		const char* what() { return "bad arguments in gmean()\n"; }
		virtual ~bad_gmean() throw() {}
	private:
		string name;
};

bad_gmean::bad_gmean(const string& n,const string& s,double a,double b):name(n),logic_error(s),v1(a),v2(b) {}
inline const char* bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}
double hmean(double a,double b);
double gmean(double a,double b);

int main()
{
	double x,y,z;

	cout << "Enter two numbers:";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers (q to quit):";
		}
		catch(bad_hmean& bg)
		{
			cout << bg.what();
			cout << "Error message:\n";
			bg.mesg();
			cout << "try again\n";
			continue;
		}
		catch(bad_gmean& hg)
		{
			cout << hg.what();
			cout << "Error message:\n";

			cout << hg.mesg();
			cout << "Value used :" << hg.v1 << "," << hg.v2 << endl;
			cout << "Sory ,you don't get to play any more.\n";
			break;
		}
	}
	cout << "Buy!\n";

	return 0;
}

double hmean(double a,double b)
{
	if(a == b)
	{
		throw bad_hmean("hmean","Error in hmean",a,b);
	}
	return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw bad_gmean("gmean","Error in gmean",a,b);
	return sqrt(a*b);
}
