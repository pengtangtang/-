/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：tree.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _TREE_H
#define _TREE_H
typedef int data_t;
typedef struct mytree{
	data_t data;/*数据域*/
	struct mytree *lchild,*rchild;/*指针域*/
}tree;/*数结点元素类型定义*/
typedef tree* tree_t;/*树结点指针*/
tree *create_tree(int i,int n);
void create_bi_tree(tree *root);
int pridoer(tree *root);
int midledoer(tree *root);
int lastdoer(tree *root);

#endif
