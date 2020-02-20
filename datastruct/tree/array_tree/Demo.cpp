/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月10日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Tree.h"
#include <stdlib.h>
/*二叉树（数组表示）
 *完成树的基本操作：
 	1：数的创建和销毁
	2：树中结点的搜索
	3：树中结点的添加与删除
	4：树中结点的遍历

	BOOL CeateTree(Tree **pTree,Node *pRoot);	
	void DestroyTree(Tree *pTree)
	Node *SearchNode(Tree *pTree,int nodeIndex);
	BOOL AddNode(Tree *pTree,int nodeIndex,int direction,Node *pNode);
	BOOL DeleteNode(Tree *pTree,int nodeIndex,Node *pNode);
	void TreeTraverse(Tree *pTree)

	关于数组与树之间的算法转换

	int tree[n]  3   5 8  2697 		父亲结点下标*2+1 该结点左
						父亲结点小表*2+2 该结点右

				   3（0）

		            5（1）        8（2）

			2（3） 6（4） 9（5） 7（6）
 * */

int main()
{
	int root = 3;
	Tree* pTree = new Tree(10,&root);
	int node1 = 5;
	int node2 = 8;

	pTree->AddNode(0,0,&node1);
	pTree->AddNode(0,1,&node2);

	int node3 = 2;
	int node4 = 6;

	pTree->AddNode(1,0,&node3);
	pTree->AddNode(1,1,&node4);

	int node5 = 9;
	int node6 = 7;

	pTree->AddNode(2,0,&node5);
	pTree->AddNode(2,1,&node6);

	pTree->TreeTraverse();

	int node = 0;
	if(pTree->DeleteNode(0,&node))
	{
		cout << "node = " << node << endl;
	}
	pTree->TreeTraverse();




	delete pTree;
	return 0;
}

