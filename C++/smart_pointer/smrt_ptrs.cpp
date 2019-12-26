/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：smrt_ptrs.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <memory>
#if 0

class Report{
	public:
		Report(const string s):str(s) 
		{ cout << "object created\n"; }
		~Report() { cout << "object deleted\n"; }
		void comment() const{ cout << str << endl; }
	private:
		string str;
};

int main()
{
	{
		auto_ptr<Report> ps (new Report("using auto_ptr"));
		ps->comment();
	}
	{
		shared_ptr<Report> ps (new Report("using shared_ptr"));
		shared_ptr<Report> ps1 = make_shared<Report> (Report("make_shared"));
		ps1->comment();
		ps->comment();
	}
	{
		unique_ptr<Report> ps (new Report("using unique_ptr"));
		ps->comment();
	}
	return 0;
}
#else
class demo{
	public:
		demo() { cout << "demo\n"; }
		virtual ~demo() { cout << "~demo\n"; }
		void func() { cout << "func\n"; }
};

int main()
{
	shared_ptr<demo> p(new demo);
	cout << "line: " << __LINE__ << "," << p.use_count() << endl;
	weak_ptr<demo> pp = p;
	cout << "line: " << __LINE__ << "," << p.use_count() << endl;
	shared_ptr<demo> p1 = p;
	cout << "line: " << __LINE__ << "," << p.use_count() << endl;

	{
		shared_ptr<demo> p2(p);
	cout << "line: " << __LINE__ << "," << p.use_count() << endl;
	}
	cout << "line: " << __LINE__ << "," << p.use_count() << endl;
	p->func();
	shared_ptr<demo> p3 = pp.lock();
	p.reset();
	p1.reset();
	p3.reset();
	
	if(pp.expired())
		cout << "demo is not exist\n";
	else
		cout << "demo is exit\n";
	return 0;
}
#endif
