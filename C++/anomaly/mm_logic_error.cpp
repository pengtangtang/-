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
#include <cstdlib>

class bad : public logic_error
{
	public:
		string name;
		double v1;
		double v2;
		explicit bad(const string& n,const string& s,double a,double b);
		void mesg();
		virtual ~bad() throw() {}
};

bad::bad(const string& n,const string& s,double a,double b):name(n),logic_error(s),v1(a),v2(b) {}

inline void bad::mesg()
{
	cout << "Error happened\n";
}

class bad_hmean : public bad
{
	public:
		explicit bad_hmean(const string& n = "hmean",const string& s = "error in hmean()",double a = 0,double b = 0);
		void mesg();
		const char* what() { return "bad arguments in hmean()\n"; }
		virtual ~bad_hmean() throw() {}
};

//调用logic_error()
bad_hmean::bad_hmean(const string& n,const string& s,double a,double b):bad(n,s,a,b) {}
inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << "," << v2 << " )invalid arguments:a = -b\n";
}

class bad_gmean : public bad
{
	public:
		explicit bad_gmean(const string& n = "gmean",const string& s = "error in gmean()",double a = 0,double b = 0);
		const char* mesg();
		const char* what() { return "bad arguments in gmean()\n"; }
		virtual ~bad_gmean() throw() {}
};

bad_gmean::bad_gmean(const string& n,const string& s,double a,double b):bad(n,s,a,b) {}
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
		catch(bad& b)
		{
			b.mesg();
			if(b.name == "hmean")
			{
				cout << ((bad_hmean& )b).what();
				cout << "Error message:\n";
				((bad_hmean &)b).mesg();
				cout << "Sory ,you don't get to play any more.\n";
				break;
			}
			else if(b.name == "gmean")
			{
				cout << ((bad_gmean &)b).what();
				cout << "Error message:\n";

			cout << ((bad_gmean &)b).mesg();
			cout << "Value used :" << ((bad_gmean &)b).v1 << "," << ((bad_gmean &)b).v2 << endl;
			cout << "Sory ,you don't get to play any more.\n";
			break;
			}
			else
			{
				cout << "Input error.\nTerminated.\n";
				system("pause");
				exit(EXIT_FAILURE);
			}
		}
	}
	cout << "Buy!\n";
	system("pause");
	return 0;
}

double hmean(double a,double b)
{
	if(a == b)
	{
		throw bad("hmean","Error in hmean",a,b);
	}
	return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw bad("gmean","Error in gmean",a,b);
	return sqrt(a*b);
}
