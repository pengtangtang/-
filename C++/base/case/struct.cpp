/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：struct.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


struct student
{
	int num;
	char name[20];
	char gender;
};

int main()
{
	student s = {10,"asd",'M'};
	cout << s.num << endl;
	cout << sizeof(s.num) << endl;
	cout << sizeof(s.name) << endl;
	cout << sizeof(s.gender) << endl;
	cout << sizeof(s) << endl; 
}
