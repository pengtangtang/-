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
#include <string.h>

Tree::Tree(int size,int* pRoot)
{
	m_iSize = size;
	m_pRoot = new int[m_iSize];
	if(NULL  == m_pRoot)
	{
		return;
	}

	memset(m_pRoot,0,m_iSize);
	m_pRoot[0] = *pRoot;
}

Tree::~Tree()
{
	delete []m_pRoot;
}

int* Tree::SearchNode(int nodeIndex)
{
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return NULL;
	}

	return &m_pRoot[nodeIndex];
}

bool Tree::AddNode(int nodeIndex,int direction,int* pNode)
{
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	if(m_pRoot[nodeIndex] == 0)
	{
		return false;
	}
	if(0 == direction)
	{
		if(nodeIndex*2+1 >= m_iSize)
		{
			return false;
		}
		if(m_pRoot[nodeIndex*2+1] != 0)
		{
			return false;
		}

		m_pRoot[nodeIndex*2+1] = *pNode;
	}
	if(1 == direction)
	{
		if(nodeIndex*2+2 >= m_iSize)
		{
			return false;
		}
		if(m_pRoot[nodeIndex*2+2] != 0)
		{
			return false;
		}

		m_pRoot[nodeIndex*2+2] = *pNode;
	}

	return true;
}

bool Tree::DeleteNode(int nodeIndex,int* pNode)
{
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}

	if(m_pRoot[nodeIndex] == 0)
	{
		return false;
	}
	if(pNode != NULL)
	{
		*pNode = m_pRoot[nodeIndex];
	}
	m_pRoot[nodeIndex] = 0;

	return true;
}

void Tree::TreeTraverse()
{
	for(int i = 0;i < m_iSize;i++)
	{
		cout << m_pRoot[i] << " ";
	}
	cout << endl;
}
