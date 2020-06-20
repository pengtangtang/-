/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：circle_func.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

const float PI = 3.14159;
const float FencePrice = 35;
const float ConcreatePrice = 20;

class Circle
{
	private:
		float radius;
	public:
		Circle(float r):radius(r) {}
		float Circumference() const
		{ return 2*PI*radius; }
		float Area() const
		{ return PI*radius*radius; }
};


int main()
{
	float radius;
	float FenceCost,ConcreateCost;

	cout << "enter the radius of the pool:";
	cin >> radius;

	Circle Pool(radius);
	Circle PoolRim(radius+3);

	FenceCost = PoolRim.Circumference()*FencePrice;
	cout << "FenceCount: " << FenceCost << endl;

	ConcreateCost = (PoolRim.Area() - Pool.Area())*ConcreatePrice;
	cout << "ConcreateCost: " << ConcreateCost << endl;
	return 0;
}

