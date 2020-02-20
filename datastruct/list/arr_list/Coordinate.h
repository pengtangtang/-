/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Coordinate.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _COORDINATE_H
#define _COORDINATE_H
#include <ostream>
using namespace std;

class Coordinate
{
	friend ostream& operator << (ostream& out,Coordinate& coor);
public:
	Coordinate(int x = 0,int y = 0);
	void printCoordinate();
	bool operator == (Coordinate& e);
private:

	int m_iX;
	int m_iY;
};

#endif
