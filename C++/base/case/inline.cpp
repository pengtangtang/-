/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：inline.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

inline double CalArea(double radius);

int main()
{
	double r(3.0);
	double area;
	area = CalArea(r);

	cout << area << endl;

	return 0;
}
inline double CalArea(double radius)
{
	return 3.14*radius*radius;
}
