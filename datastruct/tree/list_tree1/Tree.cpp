/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Tree.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Tree.h"
#include "Node.h"

Tree::Tree()//根结点
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	//DeleteNode(0,NULL);
	m_pRoot->DeleteNode();
}

bool Tree::AddNode(int nodeIndex,int direction,Node* pNode)
{
	Node* temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}

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

	return true;
}

Node* Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::DeleteNode(int nodeIndex,Node* pNode)
{
	Node* temp = SearchNode(nodeIndex);
	if(NULL == temp)
	{
		return false;
	}

	if(pNode != NULL)
	{
		pNode->data = temp->data;
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
