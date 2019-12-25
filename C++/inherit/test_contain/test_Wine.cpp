/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：test_Wine.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
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

	int y[YRS] = {1992,1978,1900};
	int b[YRS] = {98,44,66};

	Wine more("wuliangye",YRS,y,b);
	more.Show();
	cout << "total bottles of" << more.Lable() << ": " << more.Sum() << endl;
	return 0;
}
