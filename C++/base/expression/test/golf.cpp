/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：golf.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "golf.h"
#include <cstring>

void setgolf(golf &g,const char* name,int hc)
{
	strcpy(g.fullname,name);
	g.handicap = hc;
}

int setgolf(golf &g)
{
	cin.get();
	cout << "input golf name:";
	while(cin.get(g.fullname,len))
	{
		cout << "input handicap:";
		cin >> g.handicap;
		return 1;
	
	cin.get();
	return 0;
}

void handicap(golf &g,int hc)
{
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	cout << "name : " << g.fullname << " handicap:" << g.handicap << endl;
}

