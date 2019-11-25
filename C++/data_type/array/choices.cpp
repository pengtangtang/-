/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：choices.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月20日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <array>
#include <vector>

/*比较数组 vector对象 array对象*/

int main()
{
	double a1[4] = {1.2,23.0,4.3,8.8};

	vector<double> a2(4);
	a2[0] = 1.0/3.0;
	a2[1] = 1.0/7.0;
	a2[2] = 1.0/8.0;
	a2[3] = 1.0/9.0;

	array<double,4> a3 = {2.2,3.4,5.4,1.2};
	array<double,4> a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	a1[-2] = 20.9;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	return 0;
}
