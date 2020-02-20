/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Node.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Node.h"

Node::Node()
{
	index = data = 0;
	pLChild = pRChild = pParent = NULL;
}
Node::~Node()
{

}

Node* Node::SearchNode(int nodeIndex)
{
	if(this->index == nodeIndex)
	{
		return this;
	}

	Node* temp = NULL;
	if(this->pLChild != NULL)
	{
		if(this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
		else
		{
			temp = this->pLChild->SearchNode(nodeIndex);
			if(NULL != temp)
			{
				return temp;
			}
		}
	}
	if(this->pRChild != NULL)
	{
		if(this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp = this->pRChild->SearchNode(nodeIndex);
			if(NULL != temp)
			{
				return temp;			
			}
		}
	}

	return NULL;
}

void Node::DeleteNode()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	if(this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	if(this->pParent != NULL)
	{
		if(this->pParent->pLChild == this)
		{
			this->pParent->pLChild = NULL;
		}
		if(this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}
	}

	delete this;
}

void Node::PreorderTraversal()
{
	cout << index << "--" << data << endl;

	if(this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}

	if(this->pRChild != NULL)
	{
	
		this->pRChild->PreorderTraversal();
	}
}
void Node::InorderTraversal()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}

	cout << index << "--" << data << endl;
	if(this->pRChild != NULL)
	{
	
		this->pRChild->PreorderTraversal();
	}
}
void Node::PostorderTraversal()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}

	if(this->pRChild != NULL)
	{
	
		this->pRChild->PreorderTraversal();
	}
	cout << index << "--" << data << endl;
}
