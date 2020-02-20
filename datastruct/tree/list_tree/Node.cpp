/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Node.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月14日
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
{}


Node* Node::SearchNode(int nodeIndex)
{
	/*1：判断当前结点是否为要寻找的结点
	 * 2：判断左右孩子
	 * 	1）判断孩子是否为空
	 * 	2）判断孩子是否为要寻找的孩子
	 * 		1:若不是要寻找的孩子就递归寻找*/
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
			if(temp != NULL)
			{
				return temp;
			}
		}
	}

	return NULL;
}

void Node::DeleteNode()
{
	/*1：判断删除结点是否有孩子
	 * 2：依次删除该结点的孩子
	 * 3：判断孩子位于父亲结点的哪个位置，将其位置设为空
	 * 4：删除该结点*/
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
	cout << this->index << "--" << this->data << endl;

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
		this->pLChild->InorderTraversal();
	}
	cout << this->index << "--" << this->data << endl;
	if(this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}
	if(this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	cout << this->index << "--" << this->data << endl;
}

