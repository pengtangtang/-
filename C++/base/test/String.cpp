/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：String.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>

int main()
{

	char charr1[20];
	char charr2[20] = "jijia";

	string str1;
	string str2 = "panthde";

	cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feine: ";
	cin >> str1;

	cout << "Here are some felines:\n"
		<< charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << "\n";
	cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;
	return 0;
}
