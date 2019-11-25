/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：adjacency_matrix.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _ADJACENCY_MATRIX_H
#define _ADJACENCY_MATRIX_H

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 0
#define TRUE 1
#define FALSE 0
typedef int Boolean;
Boolean visited[MAXVEX];

typedef struct{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;

MGraph *CreateMGraph();
void DFS(MGraph *G，int i);
void DFSTraverse(MGraph *G);
void BFS(MGraph *G,Queue &Q,int &Q,int v,int visited[]);
#endif
