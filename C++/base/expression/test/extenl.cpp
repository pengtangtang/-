/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：extenl.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月20日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

double warming = 0.3;
void update(double dt);
void local();

int main()
{

	cout << "global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "global warming is " << warming << " degrees.\n";
	local();
	cout << "global warming is " << warming << " degrees.\n";
	return 0;
}
