/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file1.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月21日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

void other();
void another();
int x = 10;
int y;

int main()
{
	cout << x << endl;
	{
		int x = 4;
		cout << x << endl;
		cout << y << endl;

	}
	other();
	another();
	return 0;
}

void other()
{
	int y = 1;
	cout << "other:" << x << "," << y << endl;
}
