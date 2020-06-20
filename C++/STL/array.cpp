/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：array.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
/*数组 vector对象 array对象使用比较*/

#include <array>
#include <vector>

int main()
{
	double a1[4] = {1.2,2.1,2.4,3.6};

	vector<double> a2(4);

	a2[0] = 1.1;
	a2[1] = 1.1;
	a2[2] = 1.1;
	a2[3] = 1.1;

	array<double,4> a3 = {3.12,4.23,1.11,99.9};
	array<double,4> a4;
	a4 = a3;

	cout << a1[0] << endl
		<< a2[0] << endl
		<< a3[0] << endl;

	return 0;
}
