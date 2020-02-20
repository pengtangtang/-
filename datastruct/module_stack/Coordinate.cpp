/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Coordinate.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月16日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Coordinate.h"

Coordinate::Coordinate(int x,int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")\n";
}

ostream& operator << (ostream& os,Coordinate& elem)
{
	os << "(" << elem.m_iX << "," << elem.m_iY << ")\n";
	return os;
}
