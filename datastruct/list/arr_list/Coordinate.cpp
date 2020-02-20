/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Coordinate.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
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
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

bool Coordinate::operator == (Coordinate& e)
{
	if(e.m_iX == m_iX && e.m_iY == m_iY)
		return true;
	return false;
}

ostream& operator << (ostream& out,Coordinate& coor )
{
	out <<  "(" << coor.m_iX << "," << coor.m_iY << ")\n";
	return out;
}
