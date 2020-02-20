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
	int root = 3;
	Tree* tree = new Tree(8,&root);

	int node1 = 3;
	int node2 = 9;
	int node3 = 8;
	int node4 = 2;
	int node5 = 3;
	int node6 = 4;
	int node7 = 9;

	tree->AddNode(0,0,&node1);
	tree->AddNode(0,1,&node2);
	tree->AddNode(1,0,&node3);
	tree->AddNode(1,1,&node4);
	tree->AddNode(2,0,&node5);
	tree->AddNode(2,1,&node6);
	tree->AddNode(3,0,&node7);

	tree->TreeTraverse();

	tree->DeleteNode(2,NULL);
	tree->TreeTraverse();

	delete tree;
	return 0;
}
