/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Person.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Person.h"

Person& Person::operator = (Person& person)
{
	name = person.name;
	phone = person.phone;
	return *this;
}
bool Person::operator == (Person& person)
{
	return (name == person.name && person.phone == phone) ? true:false;
}

ostream& operator << (ostream& os,Person& person)
{
	os << person.name << "  " << person.phone << endl;
	return os;
}
