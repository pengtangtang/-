/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：const.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

void display(const double& r);

class A
{
	public:
		A(int i,int j) { x = i;y = j; }
	private:
		int x,y;
};

int main()
{
	double d(9.5);
	display(d);
	A const a(3,4);
	return 0;
}

void display(const double &r)
{
	cout << r << endl;
}
