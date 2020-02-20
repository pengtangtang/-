/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Person.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _PERSON_H
#define _PERSON_H
#include <ostream>
#include <string.h>
using namespace std;

class Person{
		friend ostream& operator << (ostream& os,Person& person);
	public:
		Person& operator = (Person& person);
		bool operator == (Person& person);

		string name;
		string phone;
	
};

#endif
