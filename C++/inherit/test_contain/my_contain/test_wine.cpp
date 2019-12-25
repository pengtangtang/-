/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：test_wine.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Wine.h"

int main()
{
	cout << "enter name of wine: ";
	char lab[50];
	cin.getline(lab,50);
	cout << "enter number of year: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab,yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = {1990,1998,1996};
	int b[YRS] = {46,11,22};

	Wine more("gushing",YRS,y,b);
	more.Show();
	cout << "total bottles for " << more.Label() << ":" << more.Sum() << endl;
	return 0;
}
