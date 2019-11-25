/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pic.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _PICM_H
#define _PICM_H
#define MAXVEX 100;/*最大定点数*/
#define INFINITY 65535;/*无穷大*/
typedef char VertexType;/*定点类型*/
typedef int EdgeType;/*边上的权值类型*/

typedef struct
{
	VertexType vexs[MAXVEX];/*定点表*/
	EdgeType arc[MUXVEX][MAXVEX];/*邻接矩阵，边表*/
	int numVertexes,numEdges;/*定点数和边数*/
}MGraph;

void CreateMGraph(MGraph *G);

#endif
