/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Edge.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月11日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _EDGE_H
#define _EDGE_H

class Edge{
	public:
		Edge(int nodeIndexA = 0,int nodeIndexB = 0,int weight = 0);
		int m_iNodeIndexA;
		int m_iNodeIndexB;
		int m_iWeightValue;
		bool m_bSelected;
};

#endif
