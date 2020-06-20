/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：mixtype.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

struct an_year_end
{
	int year;
};

int main()
{
	an_year_end s1,s2,s3;

	s1.year = 1998;

	an_year_end* ps = &s2;
	ps->year = 1999;

	an_year_end trio[3];
	trio[0].year = 2003;

	cout << trio->year << endl;

	const an_year_end* arp[3] = {&s1,&s2,&s3};
	cout << arp[1]->year << endl;

	const an_year_end** pp = arp;
	//auto ppb = arp;

	cout << (*pp)->year << endl;
	cout << (*(pp+1))->year << endl;

	return 0;
}
