/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：throw.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	cout << "1---before try block-----\n;
	try{
		cout << "2=======Inside try block---\n";
		throw 10;
		cout << "3------after throw---\n";
	}
	catch
	return 0;
}
