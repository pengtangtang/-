/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Edge.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月11日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Edge.h"

Edge::Edge(int nodeIndexA,int nodeIndexB,int weightValue)
{
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}
