/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：pic.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "pic.h"

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("输入定点数和变数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for(i=0;i<G->numVertexes;i++)
		scanf(&G->vexs[i]);
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j] = INFINITY;
	for(k=0;k<G->numEdges;k++)
	{
		printf("输入边(vi,vj)上的下标i,j和权w:\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];
	}
}
