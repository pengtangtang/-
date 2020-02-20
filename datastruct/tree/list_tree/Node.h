/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Node.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _NODE_H
#define _NODE_H

/*二叉树的结点类
 * 属性：索引  数据 父亲指针 左孩子指针 右孩子指针
 * 方法：构造函数 析构函数 结点搜索函数 结点删除函数 结点遍历函数*/
class Node{
	public:
		Node();
		~Node();
		Node* SearchNode(int nodeIndex);
		void DeleteNode();
		void PreorderTraversal();
		void InorderTraversal();
		void PostorderTraversal();

		int index;
		int data;
		Node* pLChild;
		Node* pRChild;
		Node* pParent;
};

#endif
