/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_func_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

class A{
public:
	void m_strcpy(char *,const char *);
	void m_strcat(char *,const char *);
};

void A::m_strcpy(char *str,const char *dest)
{
	strcpy(str,dest);
}

void A::m_strcat(char *str,const char *dest)
{
	strcat(str,dest);
}

typedef void(A::*PMA)(char *,const char *);

void dispatcher(A a,PMA pma)
{
	char str[4];
	(a.*pma)(str,"abc");
	cout << str << endl;
}

void dispatcher(A *p,void (A::*pmf)(char *,const char *))
{
	char str[4];
	(p->*pmf)(str,"abc");
	cout << str << endl;
}


int main()
{
	A a1,a2;
	A *p = &a1;
	PMA pma = &A::m_strcpy;
	dispatcher(a1,pma);
	dispatcher(&a2,pma);
	return 0;

}
