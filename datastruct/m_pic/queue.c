/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：queue.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#define MAXSIZE 10
#define INFINITY 0
typedef struct{
	int front,rear;
	int data[MAXSIZE];
}Queue;

void init_queue(Queue &Q){
	Q.front = Q.rear = 0;
	int i;
	for(i=0;i<MAXSIZE;i++)
		Q.data[i] = INFINITY;
}

void enter_queue(Queue &Q,int v){
	if((Q.front+1)%MAXSIZE == Q.rear){
		printf("Queue full\n");
		return ;
	}
	Q.data[Q.front] = v;
	Q.front = (++Q.front)%MAXSIZE;
}

int delete_queue(Queue &Q){
	int i = Q.data[Q.rear];
	Q.data[Q.rear] = INFINITY;
	Q.rear = (--Q.rear)%MAXSIZ;
	return i;
}

int empty_queue(Queue Q){
	if(Q.front == Q.rear)
		return 0;
	return 1;
}

void BFS(MGraph G,Queue &Q,int v,int visited[])
{
	int a,i=0;
	enter_queue(Q,v);
	while(empty_queue(Q)){
		a = delete_queue(Q);
		visited[a] = 1;
		printf("%c\t",G.vex[a]);
		i=0;
		while(i<G.vexNum){
			if(G.arcs[a][i] == 1){
			if(visited[i]==0){
			enter_queue(Q,i);
			visited[i] = 1;
				}
			}
			i++
		}
	}
}
