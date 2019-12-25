/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：unwinding_stack.cpp
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
#include <string>
#include "obj_exception.h"

class demo{//显示程序执行过程的类
	public:
		demo(const string& str)
		{
			word = str;
			cout << "demo " << word << " create\n";
		}
		~demo()
		{
			cout << "demo " << word << "destroyed\n" ;
		}
		void show()
		{
			cout << "demo " << word << " lives\n";
		}
	private:
		string word;
};

double hmean(double a,double b);
double gmean(double a,double b);
double means(double a,double b);

int main()
{
	double x,y,z;
	{
		demo d1("Found in block main()");
		cout << "Enter two numbers:";
		while(cin >> x >> y)
		{
			try{//检查异常
				z = means(x,y);
				cout << "The means of" << x << " and " << y << " is "
					<< z << endl;
				cout << "Enter next pair:";
			}
			catch(bad_hmean& bg)
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch(bad_g_mean& hg)
			{
				cout << hg.mesg();
				cout << "Value used :" << hg.v1 << "," << hg.v2 << endl;
				cout << "Sory ,you don't get to play any more\n";
				break;
			}
		}
		d1.show();
	}
	cout << "Buy!\n";
	cin.get();
	return 0;
}

double hmean(double a,double b)
{
	if(a == -b)
		throw bad_hmean(a,b);//抛出异常，返回到可以捕获处理该异常的程序(means())
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw bad_g_mean(a,b);//抛出异常，-------（该异常的处理程序在main()）
	return sqrt(a*b);
}

double means(double a,double b)
{
	double am,bm,gm;
	demo d2("found in means()");
	am = (a+b)/2.0;

	try{//检查异常
		bm = hmean(a,b);
		gm = gmean(a,b);
	}
	catch(bad_hmean& bg)
	{
		bg.mesg();
		cout << "Caught in means()\n";
		throw;//抛出异常，返回可以处理该异常的程序段(main())
	}
	d2.show();
	return (am+bm+gm)/3.0;
}
