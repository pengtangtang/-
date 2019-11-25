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
typedef int VertexType;/*顶点类型*/
typedef int EdgeType;/*边上的权值类型*/
#define MAXVEX 100/*最大顶点数*/
#define INFINITY 65535/*最大值*/
#define TRUE 1
#define FALSE 0
typedef int Boolean;/*Boolean类型*/
Boolean visited[MAXVEX];/*访问标志的数组*/

typedef struct
{
	VertexType vexs[MAXVEX];/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];/*邻接矩阵，边表*/
	int numVertexes,numEdges;/*当前顶点数和边数*/
}MGraph;
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
		scanf("%d",&G->vexs[i]);
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

int m_DFS(MGraph *G,int i,int visited[])/*判断图中是否存在环*/
{/*若出现某个顶点有邻接关系的所有顶点均被访问过，则一定出现回路*/
	int j,vi,di;
	visited[i] = 1;
	for(di=0,vi=0,j=0;j<G->numVertexes;j++)
	{
		if(G->arc[i][j]==1)
		{
			di++;
			if(visited[j])
				vi++;
		}
	}

	if(di == vi && di != 1)
	{
		printf("有回路\n");
		return 1;
	}

	for(j=0;j<G->numVertexes;j++)
	{
		if(G->arc[i][j] && !visited[j])
		{
			if(m_DFS(G,j,visited))
			{
				return 1;
			}else{
				return 0;
			}
		}
	}
	printf("无回路\n");
}

/*求无向图的顶点a到i间的最短路径*/
void Append(int path[],int i)
{

}

void Delete(int path[])
{

}

void DFSearchPath(MGrap *G,int v,int w,int path[],int visited[],int &found)
{
	int j;
	Append(path,v);
	visited[v] = 1;
	for(j=0;j<G->numVertexes && !found;j++)
	{
		if(G->arc[v][j]==1 && !visited[j])
		{
			if(j==w)
			{
				found = 1;
				Append(path,j);
			}
			DFSearchPath(G,j,w,path,visited,found);
		}
	}

	if(!found)
		Delete(path);
}

int main()
{
	MGraph *G = CreateMGraph();
	m_DFS(G,1,visited);
	return 0;
}
