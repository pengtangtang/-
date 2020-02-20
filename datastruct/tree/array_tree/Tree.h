/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Tree.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _TREE_H
#define _TREE_H

class Tree
{
	public:
		Tree(int size,int* pRoot);
		~Tree();
		int *SearchNode(int nodeIndex);
		bool AddNode(int nodeIndex,int direction,int* pNode);
		bool DeleteNode(int nodeIndex,int* pNode);
		void TreeTraverse();

	private:
		int* m_pTree;
		int m_iSize;
};

#endif
