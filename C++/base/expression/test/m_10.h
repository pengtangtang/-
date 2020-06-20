/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：m_10.h
*   创 建 者：pengtangtang
*   创建日期：2020年03月30日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _M_10_H
#define _M_10_H

#include <string>
#include <cstring>

class Person{
	private:
		static const LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Person()
		{
			lname = "";
			fname[0] = '\0';
		}
		Person(const string& ln,const char* fn = "Heyyou")
		{
			lname = ln;
			strcpy(fname,fn);
		}
		void Show() const
		{
			cout << "lname:" << lname
				<< " fname:" << fname << endl;
		}
		void FormalShow() const
		{
			cout << "fname: " << fname << " lname:" << fname << endl;
		}
};

#endif
