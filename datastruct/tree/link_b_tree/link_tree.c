/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：link_tree.c
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
#include "link_tree.h"

bir_thr_tree mp = NULL;			
bir_thr_tree create_bir_tree(int i,int n)
{
	bir_thr_tree root = (bir_thr_tree)malloc(sizeof(bir_thr_node));
	if(!root)
		return NULL;
	int a;
	scanf("%d",&root->data);
	if(2*i <= n)
		root->lchild = create_bir_tree(2*i,n);
	else
		root->lchild = NULL;
	if(2*i+1 <= n)
		root->rchild = create_bir_tree(2*i+1,n);
	else
		root->rchild = NULL;
	return root;
}

/*中序遍历线索化*/
void in_threading(bir_thr_tree p)
{
	if(p)
	{
		in_threading(p->lchild);/*递归左子树线索化*/
		if(!p->lchild)/*没有左孩子*/
		{
			p->l_tag = thread;/*前驱线索*/
			p->lchild = mp;/*左孩子指针指向前驱*/
		}
		if(!mp->rchild)/*前驱没有右孩子*/
		{
			mp->r_tag = thread;/*后继线索*/
			mp->rchild = p;/*前驱右孩子指针指向后继*/
		}

		mp = p;/*保持pre指向p的前驱*/

		in_threading(p->rchild);/*递归右子树线索化*/

	}
}

int traverse_tree(bir_thr_tree root)
{
	if(!root)
		return -1;
	bir_thr_tree p;
	p = root->lchild;
	while(p != root)
	{
		while(p->l_tag == link)
			p = p->lchild;
		printf("%c",p->data);
		while(p->r_tag==thread && p->rchild!=root)
		{
			p = p->rchild;
			printf("%c",p->data);
		}

		p = p->rchild;
	}
	return 0;
}

