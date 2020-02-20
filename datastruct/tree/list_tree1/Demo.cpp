/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <stdio.h>
#include "Tree.h"
/*
 * 二叉树：链表实现
 *
 * Tree();
 * ~Tree();
 * Node* SearchNode(int nodeIndex);
 * bool AddNode(int nodeIndex,int direction,Node* pNode);
 * bool DeleteNode(int nodeIndex,Node* pNode);
 * void PreorderTraversal();
 * void InorderTraversal();
 * void PostorderTraversal();
 *
 * 结点要素：索引  数据  左孩子指针 右孩子指针 父结点指针
 *
 *	（0）
 *5（1）	8（2）
 2(3) 6(4)    9(5)  7(6)
 *
 * */

int main()
{

	Tree* tree = new Tree();
	Node* node1 = new Node();
	node1->index = 1;
	node1->data = 5;

	Node* node2 = new Node();
	node2->index = 2;
	node2->data = 8;

	Node* node3 = new Node();
	node3->index = 3;
	node3->data = 2;

	Node* node4 = new Node();
	node4->index = 4;
	node4->data = 6;

	Node* node5 = new Node();
	node5->index = 5;
	node5->data = 9;

	Node* node6 = new Node();
	node6->index = 6;
	node6->data = 7;

	tree->AddNode(0,0,node1);
	if(!tree->AddNode(0,1,node2))
	{
		cout << "addNode2 failed\n";
	}
	if(!tree->AddNode(1,0,node3))
	{
		cout << "addNode3 failed\n";
	}
	if(!tree->AddNode(1,1,node4))
	{
		cout << "addNode4 failed\n";
	}
	tree->AddNode(2,0,node5);
	tree->AddNode(2,1,node6);

	tree->PreorderTraversal();
	cout << endl;
#if 0
	tree->InorderTraversal();
	cout << endl;

	Node* node = new Node();
	tree->DeleteNode(1,node);
	cout << node->index << " " << node->data << endl;
	tree->PostorderTraversal();
	cout << endl;
#else
#endif
	delete tree;
	return 0;
}
