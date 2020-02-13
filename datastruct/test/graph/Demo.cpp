/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月11日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "CMap.h"


int main()
{
#if 0
	CMap* pMap = new CMap(8);

	Node* pNodeA = new Node('A');
	Node* pNodeB = new Node('B');
	Node* pNodeC = new Node('C');
	Node* pNodeD = new Node('D');
	Node* pNodeE = new Node('E');
	Node* pNodeF = new Node('F');
	Node* pNodeG = new Node('G');
	Node* pNodeH = new Node('H');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeH);
	pMap->addNode(pNodeG);

	pMap->setValueToMatrixForUndirectedGraph(0,1);
	pMap->setValueToMatrixForUndirectedGraph(0,3);
	pMap->setValueToMatrixForUndirectedGraph(1,2);
	pMap->setValueToMatrixForUndirectedGraph(1,5);
	pMap->setValueToMatrixForUndirectedGraph(3,6);
	pMap->setValueToMatrixForUndirectedGraph(3,7);
	pMap->setValueToMatrixForUndirectedGraph(6,7);
	pMap->setValueToMatrixForUndirectedGraph(2,4);
	pMap->setValueToMatrixForUndirectedGraph(2,5);

	pMap->printMatrix();
	cout << endl;

	pMap->resetNode();
	pMap->depthFirstTraverse(0);
	cout << endl;

	pMap->resetNode();
	pMap->breadthFirstTraverse(0);
	cout << endl;
#else
	CMap* pMap = new CMap(6);

	Node* pNodeA = new Node('A');
	Node* pNodeB = new Node('B');
	Node* pNodeC = new Node('C');
	Node* pNodeD = new Node('D');
	Node* pNodeE = new Node('E');
	Node* pNodeF = new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectedGraph(0,1,6);
	pMap->setValueToMatrixForUndirectedGraph(0,4,5);
	pMap->setValueToMatrixForUndirectedGraph(0,5,1);
	pMap->setValueToMatrixForUndirectedGraph(1,2,3);
	pMap->setValueToMatrixForUndirectedGraph(2,3,7);
	pMap->setValueToMatrixForUndirectedGraph(3,5,4);
	pMap->setValueToMatrixForUndirectedGraph(3,4,2);
	pMap->setValueToMatrixForUndirectedGraph(4,5,9);
	pMap->setValueToMatrixForUndirectedGraph(2,5,8);
	pMap->setValueToMatrixForUndirectedGraph(1,5,2);

	pMap->primTree(0);
	pMap->resetNode();
	cout << endl;

	pMap->kruskalTree();
	cout << endl;
#endif
	return 0;
}
