/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：static_data.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Point
{
	public:
		Point(int xx = 0,int yy = 0) { X = xx; Y = yy;countP++; }
		Point(Point &p);
		int GetX() { return X; }
		int GetY() { return Y; }
		void GetC() { cout << countP << endl; }
	private:
		int X,Y;
		static int countP;
};
int Point::countP = 0;
Point::Point(Point& p)
{
	X = p.X;
	Y = p.Y;
	countP++;
}

int main()
{
	Point A(4,5);
	cout << "Point A:" << A.GetX() << "," << A.GetY() << endl;
	A.GetC();
	return 0;
}
