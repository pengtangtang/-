/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Edge.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _EDGE_H
#define _EDGE_H
//图的边
class Edge{
public:
	Edge(int nodexIndexA = 0,int nodeIndexB = 0,int weightValue = 0);//初始化数据成员
	int m_iNodeIndexA;//边的两个顶点
	int m_iNodeIndexB;
	int m_iWeightValue;//边的权值
	bool m_bSelected;//是否已经访问的标志
};
#endif
