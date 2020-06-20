/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：must_convert.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Circle {
	private:
		double x,y,r;
	public:
		Circle(double x1,double y1,double r1) { 
			x = x1;
			y = y1;
			r = r1;
		}
		operator int() { return int(r); }
		operator double() { return 2*3.14*r; }
		operator float() { return (float)3.14*r*r; }
};

int main()
{
	Circle c(2.3,3.4,2.5);
	int r = c;
	double length = c;
	float area = c;
	double len = (double) c;
	cout << r << endl
		<< length  << endl
		<< area << endl;

}
