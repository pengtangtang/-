/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：cString.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

int main()
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "Howdy! I'm " << name2 << ".What's Your name?\n" ;
	cin >> name1;
	cout << "Well ," << name1 << ",your name has " << strlen(name1) << "letters and sored\n";
	cout << "In an array of " << sizeof(name1) << " bytes.\n";


	return 0;
}
