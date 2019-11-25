/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：tree.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "tree.h"
#include "lsequeue.h"

#if 1
/*生成自己想要的二叉树，i起始结点，n一共有多少结点数*/
tree *create_tree(int i,int n)
{
	tree *root = (tree *)malloc(sizeof(tree));
	if(NULL == root)
		return NULL;
	int a;
	scanf("%d",&root->data);/*输入自己想设定的结点元素*/
	if(2*i <= n)
		root->lchild = create_tree(2*i,n);
	else
		root->lchild = NULL;
	if(2*i+1 <= n)
		root->rchild = create_tree(2*i+1,n);
	else
		root->rchild = NULL;
	return root;

}
#else
tree *create_tree(int i,int n)/*创建一颗树*/
{/*递归思想，先左后右，逐层调用与返回*/
	tree *root = (tree *)malloc(sizeof(tree));
	if(NULL == root)
		return NULL;
	root->data = i;
	if(2*i <= n)/*左孩子*/
		root->lchild = create_tree(2*i,n);
	else
		root->lchild = NULL;

	if(2*i+1 <= n)/*右孩子*/
		root->rchild = create_tree(2*i+1,n);
	else 
		root->rchild = NULL;
	return root;
}

#endif

int pri_order(tree *root)/*先序遍历：根左右*/
{
	if(NULL == root)
		return -1;
	data_t data = root->data;
	printf("%-4d",data);
	pri_order(root->lchild);
	pri_order(root->rchild);
	return 0;
}
int midle_order(tree *root)/*中序遍历：左根右*/
{
	if(NULL == root)
		return -1;
	midle_order(root->lchild);
	data_t data = root->data;
	printf("%-4d",data);
	midle_order(root->rchild);
	return 0;
}
int last_order(tree *root)/*后序遍历：左右根*/
{
	if(NULL == root)
		return -1;
	last_order(root->lchild);
	last_order(root->rchild);
	data_t data = root->data;
	printf("%-4d",data);
	return 0;
}

int level_order(tree *root)/*层序遍历：利用链式队列，将根结点入队后，判断队列是否为空，不为空则出队，并判断是否有左右孩子，有的话就入队，不断循环，直到将树遍历完*/
{
	if(NULL == root)
		return -1;

	lsequeue *lq = create_lsequeue();
	in_lsequeue(lq,root);

	while(lsequeue_is_empty(lq) == 0)/*队列不为空*/
	{
		tree_t root=out_lsequeue(lq);
		printf("%-4d",root->data);
		if(root->lchild != NULL)
		{
			in_lsequeue(lq,root->lchild);
		}
		if(root->rchild != NULL)
		{
			in_lsequeue(lq,root->rchild);
		}
	}
	return 0;
}
