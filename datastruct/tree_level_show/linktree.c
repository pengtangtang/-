/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linktree.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "linktree.h"
#include "linkqueue.h"

tree *createtree(int i,int n)//创建有序数
{
	tree *root=(tree *)malloc(sizeof(tree));
	if(root==NULL)
		return 	NULL;
	root->data=i;
	if(2*i<=n)//创建左孩子
	{
		root->lchild=createtree(2*i,n);
	}
	else
		root->lchild=NULL;
	if(2*i+1<=n)
	{
		root->rchild=createtree(2*i+1,n);
	}
	else
		root->rchild=NULL;

	return root;
}

int priorder(tree *root)
{
	if(root==NULL)
		return -1;
	data_t data=root->data;
	printf("%-2d ",data);
	priorder(root->lchild);
	priorder(root->rchild);
	return 0;
}

int tree_level_show(tree *root)//层次遍历
{
	if(root==NULL)
		return -1;
	lsequeue *lq=create_lsequeue();
	in_lsequeue(lq,root);//入队
	while(lsequeue_is_empty(lq)==0)
	{
		tree_t root=out_lsequeue(lq);//将根结点出队，若有孩子则下一个出队元素为孩子
		printf(" %d ",root->data);
		if(root->lchild!=NULL)//判断是否有左孩子
		{
			in_lsequeue(lq,root->lchild);//入队
		}
		if(root->rchild!=NULL)//判断是否有右孩子
		{
			in_lsequeue(lq,root->rchild);//入队
		}
	}
	return 0;
}
