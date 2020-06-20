/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：support.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月20日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

extern double warming;

void update(double dt);
void local();

void updata(double dt)
{
	extern double warming;
	warming += dt;
	cout << "updating global warming to " << warming << "degrees.\n";
}

void local()
{
	double warming = 0.8;

	cout << "local warming = " << warming << " degrees.\n";
	cout << "global warming = " << ::warming << "degrees.\n";
}
