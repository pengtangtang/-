/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pic.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月06日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
typedef int  VertexType;/*顶点类型*/
typedef int EdgeType;/*边上的权值类型*/
#define MAXVEX 100/*最大顶点数*/
#define INFINITY 0/*初始值*/
#define TRUE 1
#define FALSE 0

typedef int Boolean;/*Boolean类型*/
Boolean visited[MAXVEX];/*访问标志的数组*/

typedef struct EdgeNode{
	int adjvex;
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges;/*当前顶点数和边数*/
}GraphAdjList;

GraphAdjList *CreateMGraph()
{
	GraphAdjList *G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
	if(!G)
		return NULL;
	int i,j,k;
	EdgeNode *e;
	printf("请输入顶点数和边数:\n");
	scanf("%d %d",&G->numVertexes,&G->numEdges);

	printf("请输入顶点下标：\n");
	for(i=0;i<G->numVertexes;i++)/*读入顶点信息，建立顶点表*/
	{
		scanf("%d",&G->vexs[i]);
		G->adjList[i].fiartedge = NULL;
	}
	for(k=0;k<G->numEdges;k++)/*建立边表*/
	{
		printf("边%d:",k);
		scanf("%d %d",&i,&j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));

		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
	return G;
}

void DFS(GraphAdjList* G,int i)/*邻接表的深度优先递归算法*/
{
	int j;
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%d ",G->vexs[i].data);/*打印顶点，也可以是其他操作*/
	p = G->adjList[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(GraphAdjList* G)/*邻接表的深度遍历操作*/
{
	int i;
	for(i=0;i<G->numVertexes;i++)
		visited[i] = FALSE;/*初始所有顶点状态都是未访问*/
	for(i=0;i<G->numVertexes;i++)
	{
		if(!visited[i])/*对未访问过的顶点调用DFS，若是连通图，则只执行一次*/
			DFS(G,i);
	}
}

int main()
{
	GraphAdjList *G = CreateMGraph();
	DFSTraverse(G);
	return 0;
}
