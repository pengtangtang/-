/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：new_delete.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

char* getname();

int main()
{
	char* name;
	name = getname();

	cout << name << " at " << (int*)name << endl;
	delete name;
	return 0;
}

char* getname()
{
	char temp[80];
	cout << "enter last name:";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];

	strcpy(pn,temp);

	return pn;
}
