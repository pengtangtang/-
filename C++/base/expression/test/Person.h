/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：10.h
*   创 建 者：pengtangtang
*   创建日期：2020年03月30日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _10_H
#define _10_H
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Person
{
	private:
		static const LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Person() {lname = " ",fname[0] = '\0'; }
		Person(const string& ln,const char* fn = "Heyyou");
		void Show() const;
		void FormalShow() const;
};

Person::Person(const string& ln,const char* fn = "Heyyou")
{
	lname = ln;
	strcpy(fname,fn);
}

void Person::Show() const
{
	cout << "lname:" << lname
		<< "	fname:" << fname << endl;
}

void Person::FormalShow() const
{
	cout << "fname:" << fname << endl;
}
#endif
