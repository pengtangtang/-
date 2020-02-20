/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
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

int main()
{
	Tree* tree = new Tree();
	if(NULL == tree)
	{
		return -1;
	}

	Node* node1 = new Node();
	node1->index = 1;
	node1->data = 9;

	Node* node2 = new Node();
	node2->index = 2;
	node2->data = 2;

	Node* node3 = new Node();
	node3->index = 3;
	node3->data = 0;

	tree->AddNode(0,0,node1);
	tree->AddNode(0,1,node2);
	tree->AddNode(1,0,node3);

	tree->DeleteNode(3,NULL);

	tree->PreorderTraversal();
	cout << endl;
}
