/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file2.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

extern int x;
namespace 
{
	int y = 4;
}

void another()
{
	cout << "another():" << x << "," << y << endl;
}
