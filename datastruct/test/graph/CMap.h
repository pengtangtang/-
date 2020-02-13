/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：CMap.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月10日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _CMAP_H
#define _CMAP_H

#include "Node.h"
#include "Edge.h"
#include <vector>

class CMap{
	public:
		CMap(int capacity);
		~CMap();
		bool addNode(Node* pNode);
		void resetNode();//重置顶点状态
		bool setValueToMatrixForDirectedGraph(int row,int col,int val = 1);//设置边信息，有向图
		bool setValueToMatrixForUndirectedGraph(int row,int col,int val = 1);//设置边信息，无向图

		void printMatrix();//打印临界矩阵

		void depthFirstTraverse(int nodeIndex);//深度优先遍历
		void breadthFirstTraverse(int nodeIndex);//广度优先遍历

		void primTree(int nodeIndex);
		void kruskalTree();
	private:
		bool getValueFromMatrix(int row,int col,int& val);
		void breadthFirstTraverseImp(vector<int> preVec);

		int getMinEdge(vector<Edge> edgeVec);
		bool isInSet(vector<int> nodeSet,int target);
		void mergeNodeSet(vector<int>& nodeSetA,vector<int> nodeSetB);
	private:
		int m_iCapacity;//图的所有顶点
		int m_iNodeCount;//当前顶点数
		Node* m_pNodeArray;//顶点数组
		int* m_pMatrix;//临界矩阵

		Edge* m_pEdge;
};

#endif
