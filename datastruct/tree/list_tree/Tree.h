/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Tree.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _TREE_H
#define _TREE_H
#include "Node.h"

class Tree{
	public:
		Tree();
		~Tree();
		Node* SearchNode(int nodeIndex);
		bool AddNode(int nodeIndex,int direction,Node* pNode);
		bool DeleteNode(int nodeIndex,Node* pNode);
		void PreorderTraversal();
		void InorderTraversal();
		void PostorderTraversal();
	private:

		Node* m_pRoot;
};
#endif
