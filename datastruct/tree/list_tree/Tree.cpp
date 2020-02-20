/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Tree.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Tree.h"
#include <stdio.h>
Tree::Tree()
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	m_pRoot->DeleteNode();
}

Node* Tree::SearchNode(int nodeIndex )
{
	/*将结点寻找转移到根结点的结点寻找*/
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex,int direction,Node* pNode)
{/*nodeIndex---要挂载的父亲结点		direction---位于父亲结点的哪个孩子（0--左 1--右）  pNode--要挂载的结点

1：判断要挂载的父亲结点是否存在
2：根据方位挂载*/
	Node* temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
#if 0
	//出现double free
	pNode->pParent = temp;
	if(0 == direction)
	{
		temp->pLChild = pNode;
	}
	if(1 == direction)
	{
		temp->pRChild = pNode;
	}
#else
	Node* node = new Node();
	if(NULL == node)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;

	if(0 == direction)
	{
		temp->pLChild = node;
	}
	if(1 == direction)
	{
		temp->pRChild = node;
	}
#endif
	return true;
}

bool Tree::DeleteNode(int nodeIndex,Node* pNode)
{
	Node* temp = SearchNode(nodeIndex);
	if(NULL == temp)
	{
		return false;
	}

	if(NULL != pNode)
	{
		temp->data = pNode->data;
	}

	temp->DeleteNode();
	return true;

}

void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}
void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}
void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}
