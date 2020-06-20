/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Cin.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
	cout << "What year was your house buit?\n";

	int year;
#if 0
	cin >> year;
	cin.get();
#else
	(cin >> year).get();
#endif

	cout << "What is its street address?\n";

	char address[80];
	cin.getline(address,80);

	cout << "Year buit: " << year << endl;
	cout << "Address: " << address << endl << "Done\n";

	cin.clear();

	return 0;
}
