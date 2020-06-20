/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：enum.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

enum weekday
{
	s,m,t,w,thu,f,s1
};

int main()
{
	enum weekday wek = s;
	//weekday wek = s;
	for (int i = wek;i != f;i++)
	{
		cout << i << endl;
		cout << wek + s << endl;
		cout << "-----------------\n";
	}
	return 0;
}
