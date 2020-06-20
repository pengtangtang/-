/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：run_year.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main(int argc,char const *argv[])
{
	int year;
	bool isLeapYear;
	cout << "enter the year:";
	cin >> year;
	isLeapYear = (((year%4==0) && (year%100!=0)) || (year%400==0));
	if (isLeapYear)
		cout << year << " is leap year\n";
	else
		cout << year << " is not year\n";

	return 0;
}
