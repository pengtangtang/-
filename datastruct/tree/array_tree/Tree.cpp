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
#include <string.h>

Tree::Tree(int size,int *pRoot)
{
	m_iSize = size;
	m_pTree = new int[m_iSize];
	if(m_pTree == NULL)
	{
		return ;
	}

	memset(m_pTree,0,m_iSize);
	m_pTree[0] = *pRoot;
}

Tree::~Tree()
{
	delete []m_pTree;
}

int* Tree::SearchNode(int nodeIndex)
{
	if(0 > nodeIndex || nodeIndex >= m_iSize)
		return NULL;
	if(m_pTree[nodeIndex] == 0)
		return NULL;
	return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex,int direction,int *pNode)
{
	if(0 > nodeIndex || nodeIndex >= m_iSize)
		return false;
	if(m_pTree[nodeIndex] == 0)
		return false;

	if(direction == 0)//左孩子
	{
		if(nodeIndex*2+1 >= m_iSize)
			return false;
		if(m_pTree[nodeIndex*2+1] != 0)
			return false;
		m_pTree[nodeIndex*2+1] = *pNode;
	}
	if(direction == 1)//右孩子
	{
		if(nodeIndex*2+2 >= m_iSize)
			return false;
		if(m_pTree[nodeIndex*2+2] != 0)
			return false;
		m_pTree[nodeIndex*2+2] = *pNode;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex,int *pNode)
{
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
		return false;
	if(m_pTree[nodeIndex] == 0)
		return false;
	if(pNode != NULL)
	{
		*pNode = m_pTree[nodeIndex];
	}
	m_pTree[nodeIndex] = 0;//删除结点

	return true;
}

void Tree::TreeTraverse()
{
	for(int i = 0;i  < m_iSize;i++)
	{
		cout << m_pTree[i] << " ";
	}
	cout << endl;
}
