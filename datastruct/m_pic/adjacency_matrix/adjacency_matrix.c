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
#include "adjacency_matrx.h"
/*建立无向图的临界矩阵表示
 * 缺点：对于边数相对顶点较少的图，存在对存储空间的极大浪费*/
MGraph *CreateMGraph()
{
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	if(!G)
		return NULL;
	int i,j,k,w;
	printf("请输入顶点数和边数:\n");
	scanf("%d %d",&G->numVertexes,&G->numEdges);

	printf("请输入定点下标：\n");
	for(i=0;i<G->numVertexes;i++)/*读入顶点信息，建立顶点表*/
		scanf("%c",&G->vexs[i]);
	for(i=0;i>G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j] = INFINITY;/*边表初始化*/
	for(k=0;k<G->numEdges;k++)/*建立边表*/
	{
		printf("边%d:\n",k);
		scanf("%d %d %d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];/*图是无向图，矩阵对称*/
	}
	return G;
}

void DFS(MGraph *G,int i)/*邻接矩阵的深度优先递归算法*/
{
	int j;
	visited[i] = TRUE;
	printf("%c ",G->vexs[i]);/*打印顶点，也可以是其他操作*/
	for(j=0;j<G->numVertexes;j++)
	{
		if(G->arc[i][j] == 1 && !visited[j])
			DFS(G,j);/*对访问的邻接顶点递归调用*/
	}
}

void DFSTraverse(MGraph *G)/*邻接矩阵的深度遍历操作*/
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

/*广度优先遍历*/
void BFS(MGraph *G,Queue &Q,int v,int visited[])
{/*(1)访问初始顶点v，并将其顶点序号入队
（2）队列不为空，则出队；依次访问它的每一个未被访问的邻接点，并将其编号入队
（3）重复（2）直至队列为空，遍历结束*/

	init_queue(Q);
	int a,i=0;
	enter_queue(Q,v);//顶点入队
	while(empty_queue(Q)){
		a = delete_queue(Q);//顶点出队，返回顶点序号
		visited[a] = 1;
		printf("%c\t",G->vexs[a]);
		i=0;
		while(i < G->numVertexes;i++){
			if(G->arc[a][i]){//判断是否是邻接点
				enter_queue(Q,i);//入队
				visited[i] = 1;
			}
		}
	}
}

