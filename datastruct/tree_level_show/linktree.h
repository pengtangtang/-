/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：linktree.h
*   创 建 者：pengtangtang
*   创建日期：2019年08月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINKTREE_H
#define _LINKTREE_H
typedef int data_t;
typedef struct mytree{
	data_t data;
	struct mytree *lchild,*rchild;
}tree;
typedef tree *tree_t;
tree *createtree(int i,int n);//建立结点,i结点编号，n结点总数
int priorder(tree *root);//先序遍历
int tree_level_show(tree *root);//层次遍历
#endif
