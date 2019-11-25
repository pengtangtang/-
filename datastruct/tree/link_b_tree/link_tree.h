/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：link_tree.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINK_TREE_H
#define _LINK_TREE_H
/*二叉线索存储结构定义*/
typedef enum{link,thread} pointer_tag;
typedef int data_t;
typedef struct bi_thr_node{
	data_t data;
	struct bi_thr_node *lchild,*rchild;
	pointer_tag l_tag,r_tag;
}bir_thr_node,*bir_thr_tree;

int traverse_tree(bir_thr_tree root);


#endif
