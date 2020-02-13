/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：CMap.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2020年02月08日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>
#include "CMap.h"
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <string.h>

/*CMap:初始化数据成员*/
CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity*m_iCapacity];
	memset(m_pMatrix,0,m_iCapacity*m_iCapacity*sizeof(int));

	m_pEdge = new Edge[m_iCapacity-1];
}

/*～CMap:释放存储空间*/
CMap::~CMap()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
	delete []m_pEdge;
}

/*addNode::结点添加函数
 * 注意判断参数，将结点添加到结点数组*/
bool CMap::addNode(Node* pNode)
{
	if(NULL == pNode)
	{
		return false;
	}

	m_pNodeArray[m_iNodeCount] = pNode->m_cData;
	m_iNodeCount++;

	return true;
}
/*resetNode:重置结点数组中所有结点的访问标志*/
void CMap::resetNode()
{
	for(int i = 0;i < m_iCapacity;i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}


/*setValueToMatrixForDirectedGraph:设置两顶点间是否有边---临界矩阵的值，有向图*/
bool CMap::setValueToMatrixForDirectedGraph(int row,int col,int val)
{
	if(row < 0 || row >= m_iCapacity)
		return false;
	if(col < 0 || col >= m_iCapacity)
		return false;

	m_pMatrix[row*m_iCapacity+col] = val;

	return true;
}
/*setValueToMatrixForUndirectedGraph:设置两顶点间是否有边---临界矩阵的值，无向图*/
bool CMap::setValueToMatrixForUndirectedGraph(int row,int col,int val)
{
	if(row < 0 || row >= m_iCapacity)
		return false;
	if(col < 0 || col >= m_iCapacity)
		return false;

	m_pMatrix[row*m_iCapacity+col] = val;
	m_pMatrix[col*m_iCapacity+row] = val;

	return true;
}
/*getValueFromMatrix:获取两顶点之间是否有边的信息*/
bool CMap::getValueFromMatrix(int row,int col,int& val)
{
	if(col < 0 || col >= m_iCapacity)
		return false;
	if(row < 0 || row >= m_iCapacity)
		return false;

	val = m_pMatrix[row*m_iCapacity+col];

	return true;
}

/*printMatrix:临界矩阵打印函数*/
void CMap::printMatrix()
{
	for(int i = 0;i < m_iCapacity;i++)
	{
		for(int j = 0;j < m_iCapacity;j++)
		{
			cout << m_pMatrix[i*m_iCapacity+j] << " ";
		}
		cout << endl;
	}
}
/*深度优先遍历函数：
 * 	1：由参数指定第一个遍历顶点
 * 	2：寻找与当前顶点相关的点，找到第一个点后，递归--寻找第一个点相关的第一个点*/

void CMap::depthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	int val = 0;
	for(int i = 0;i < m_iCapacity;i++)
	{
		getValueFromMatrix(nodeIndex,i,val);
		if(val != 0)
		{
			if(m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else
		{
			continue;
		}
	}
}

//广度优先遍历：1：指定第一个访问结点，并打印该结点数据，标识该结点为已经访问
//		2：创建数组来保存本层顶点
//		3：遍历与本层顶点相关的其他顶点
//			1）创建数组。保存顶点
//			2）获取与本层顶点相关的其他顶点，使用递归不




void CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImp(curVec);
}


void CMap::breadthFirstTraverseImp(vector<int> preVec)
{
	vector<int> curVec;
	int val = 0;

	for(int i = 0;i < (int)preVec.size();i++)
	{
		for(int j = 0;j < m_iCapacity;j++)
		{
			getValueFromMatrix(preVec[i],j,val);
			{
				if(val != 0)
				{
					if(m_pNodeArray[j].m_bIsVisited)
					{
						continue;
					}
					else
					{
						cout << m_pNodeArray[j].m_cData << " ";
						m_pNodeArray[j].m_bIsVisited = true;
						curVec.push_back(j);
					}
				}
			}
		}

		if(curVec.size() == 0)
		{
			return ;
		}
		else
		{
			breadthFirstTraverseImp(curVec);
		}
	}
}



//普利姆算法生成最小树:适合各个顶点都相连的图
//图：顶点与边组成----新增边的类
//1：根据点找出与之相关的所有边
//2：找出所有边之间的权值最小边，并标记边，且将此边放入最小生成树的集合
//3：找到与最小边相关的另一个顶点，放入点集合
#if 1

void CMap::primTree(int nodeIndex)
{
	int val = 0;
	int edgeCount = 0;

	vector<int> nodeVec;
	vector<Edge> edgeVec;

	cout << m_pNodeArray[nodeIndex].m_cData << endl;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	nodeVec.push_back(nodeIndex);

	while(edgeCount < m_iCapacity-1)
	{
		int temp = nodeVec.back();
		for(int i = 0;i < m_iCapacity;i++)
		{
			getValueFromMatrix(temp,i,val);
			if(val != 0)
			{
				if(m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					Edge edge(temp,i,val);
					edgeVec.push_back(edge);
				}
			}
		}
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		cout << edgeVec[edgeIndex].m_iNodeIndexA << "---" << edgeVec[edgeIndex].m_iNodeIndexB << "  ";
		cout << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;
	int edgeIndex = 0;

	int i = 0;
	for(;i < edgeVec.size();i++)
	{
		if(!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}

	if(0 == minWeight)
	{
		return -1;
	}

	for(;i < edgeVec.size();i++)
	{
		if(edgeVec[i].m_bSelected)
		{
			continue;
		}
		else
		{
			if(minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}

	return edgeIndex;
}

#else
void CMap::primTree(int nodeIndex)
{
	vector<Edge> edgeVec;
	int val = 0;
	int edgeCount = 0;
	vector<int> nodeVec;

	cout << m_pNodeArray[nodeIndex].m_cData << endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;


	while(edgeCount < m_iCapacity-1)
	{
		int temp = nodeVec.back();

	for(int i = 0;i < m_iCapacity;i++)
	{
		getValueFromMatrix(temp,i,val);
		if(val != 0)
		{
			if(m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				Edge mEdge(temp,i,val);
				edgeVec.push_back(mEdge);

			}
		}
	}
	
	int edgeIndex = getMinEdge(edgeVec);
	edgeVec[edgeIndex].m_bSelected = true;

	cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << " ";
	cout << edgeVec[edgeIndex].m_iWeightValue << endl;

	m_pEdge[edgeCount] = edgeVec[edgeIndex];
	edgeCount++;

	int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

	nodeVec.push_back(nextNodeIndex);
	m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

	cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}

}

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;
	int edgeIndex = 0;

	int i = 0;

	for(;i < edgeVec.size();i++)
	{
		if(!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}

	if(minWeight == 0)
	{
		return -1;
	}

	for(;i < (int)edgeVec.size();i++)
	{
		if(edgeVec[i].m_bSelected)
		{
			continue;
		}
		else
		{
			if(minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}

	return edgeIndex;
}
#endif
/*找出最小权值边
 *1：找出第一条没有被遍历的边，
  2：判断是否所有的边已经遍历完了
3:和没有遍历的边比较权值并记录最小的边
 * */


/*克鲁斯卡尔算法：以边为核心，找出最小生成树的边集合
 * 算法：1：找出所有的边
 * 	 2：找出组成最小生成树的边集合
 * 	 	1）找到算法结束条件
 * 	 	2）从边集合中找到最小边
 * 	 	3）找出最小边连接的点
 * 	 	4）找出点所在的点集合
 		5）根据点所在集合的不同做出不同的处理(避免出现闭环问题，否则会违背最小生成树的原理)*/
#if 1
void CMap::kruskalTree()
{
	vector<Edge> edgeVec;
	vector< vector<int> > nodeSet;

	int edgeCount = 0;
	int val = 0;

	for(int i = 0;i < m_iCapacity;i++)
	{
		for(int j = 0;j < m_iCapacity;j++)
		{
			getValueFromMatrix(i,j,val);
			if(val != 0)
			{
				if(!m_pNodeArray[j].m_bIsVisited)
				{
					Edge edge(i,j,val);
					edgeVec.push_back(edge);
				}
			}
		}
	}

	while(edgeCount < m_iCapacity-1)
	{
	int minEdgeIndex = getMinEdge(edgeVec);
	edgeVec[minEdgeIndex].m_bSelected = true;

	int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
	int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

	bool nodeAIsInSet = false;
	bool nodeBIsInSet = false;

	int nodeAInSetLabel = -1;
	int nodeBInSetLabel = -1;

	for(int i = 0;i < nodeSet.size();i++)
	{
		if(nodeAIsInSet)
		{
			nodeAInSetLabel = i;
		}
	}

	for(int i = 0;i < nodeSet.size();i++)
	{
	
		if(nodeBIsInSet)
		{
			nodeBInSetLabel = i;
		}
	}

	if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
	{
		vector<int> vec;
		vec.push_back(nodeAIndex);
		vec.push_back(nodeBIndex);
		nodeSet.push_back(vec);
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
	{
		nodeSet[nodeAInSetLabel].push_back(nodeBIndex);
	}
	else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
	{
		nodeSet[nodeBInSetLabel].push_back(nodeAIndex);
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)
	{
		mergeNodeSet(nodeSet[nodeAInSetLabel],nodeSet[nodeBInSetLabel]);
		for(int k = nodeBInSetLabel;k < nodeSet.size();k++)
		{
			nodeSet[k] = nodeSet[k+1];
		}
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
	{
		continue;
	}

	m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
	edgeCount++;

	cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "---" << edgeVec[minEdgeIndex].m_iNodeIndexB << "  ";
	cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int> nodeSet,int target)
{
	for(int i = 0;i < nodeSet.size();i++)
	{
		if(nodeSet[i] == target)
		{
			return true;
		}
	}

	return false;
}

void CMap::mergeNodeSet(vector<int>& nodeSetA,vector<int> nodeSetB)
{
	for(int i = 0;i < nodeSetB.size();i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}
#else
void CMap::kruskalTree()
{
	vector<Edge> edgeVec;
	vector< vector<int> > nodeSets;

	int val = 0;
	int edgeCount = 0;

	for(int i = 0;i < m_iCapacity;i++)
	{
		for(int k = i+1;k < m_iCapacity;k++)
		{
			getValueFromMatrix(i,k,val);
			if(val != 0)
			{
				Edge edge(i,k,val);
				edgeVec.push_back(edge);
			}
		}
	}

	while(edgeCount < m_iCapacity-1)
	{
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;

		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

		bool nodeAIsInSet = false;
		bool nodeBIsInSet = false;

		int nodeAInSetLabel = -1;
		int nodeBInSetLabel = -1;
		
		for(int i = 0;i < (int)nodeSets.size();i++)
		{
			nodeAIsInSet = isInSet(nodeSets[i],nodeAIndex);
			if(nodeAIsInSet)
			{
				nodeAInSetLabel = i;
			}
		}
		for(int i = 0;i < (int)nodeSets.size();i++)
		{
			nodeBIsInSet = isInSet(nodeSets[i],nodeBIndex);
			if(nodeBIsInSet)
			{
				nodeBInSetLabel = i;
			}
		}

		if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);

			nodeSets.push_back(vec);
		}
		else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
		}
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		}
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)
		{
			mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
			for(int k = nodeBInSetLabel;k < (int)nodeSets.size()-1;k++)
			{
				nodeSets[k] = nodeSets[k+1];
			}
		}
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
		{
			continue;
		}

		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
		edgeCount++;

		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
			

	}
}

bool CMap::isInSet(vector<int> nodeSet,int target)
{
	for(int i = 0;i < nodeSet.size();i++)
	{
		if(nodeSet[i] == target)
		{
			return true;
		}
	}

	return false;
}

void CMap::mergeNodeSet(vector<int>& nodeSetA,vector<int> nodeSetB)
{
	for(int i = 0;i < nodeSetB.size();i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}

void CMap::kruskalTree()
{
	/*克鲁斯卡尔算法生成树，找出最小生成树边的集合*/
	//定义存放结点集合的数组
	int value = 0;
	int edgeCount = 0;//最小生成树的边数
	//定义存放结点集合的数组：所有的点可能不在同一集合
	vector< vector<int> >  nodeSets;


	//第一步：取出所有边：主对角线上半部分矩阵（无向图的临界矩阵是对称的，只需要取出一半就好了，不含对角线）
	vector<Edge> edgeVec;//存放边的集合
	for(int i = 0;i < m_iCapacity;i++)//将临界矩阵中关于边的描述，转换为Edge对象
	{
		for(int k = i+1;k < m_iCapacity;k++)
		{
			getValueFromMatrix(i,k,value);
			if(value != 0)
			{
				Edge edge(i,k,value);
				edgeVec.push_back(edge);
			}
		}
	}

	//第二部：从所有边中取出组成最小生成树的边
	//1：找到算法结束条件
	while(edgeCount < m_iCapacity-1)
	{
	//2：从边集合中找到最小边
	//1）从边集合中寻找出最小边
	//2）将已选边标记为已选取状态
	int minEdgeIndex = getMinEdge(edgeVec);
	edgeVec[minEdgeIndex].m_bSelected = true;

	//3：找到最小边连接的点
	int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
	int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

	bool nodeAIsInSet = false;
	bool nodeBIsInSet = false;

	int nodeAInSetLabel = -1;
	int nodeBInSetLabel = -1;
	//4：找出点所在的点集合？？好像是防止出现闭环问题---当两个顶点已经在一个集合中说明两个顶点已经访问过，再次访问会出现闭环问题，这就违背类最小生成树原理
	//从所有的点集合中寻找两顶点所在集合
	for(int i = 0;i < (int)nodeSets.size();i++)
	{//A点所在点集合索引
		nodeAIsInSet = isInSet(nodeSets[i],nodeAIndex);
		if(nodeAIsInSet)
		{
			nodeAInSetLabel = i;//顶点所在集合索引		
			//nodeAIsInSet = i	
		}
	}
	for(int i = 0;i < (int)nodeSets.size();i++)
	{//B点所在点集合索引
		nodeBIsInSet = isInSet(nodeSets[i],nodeBIndex);
		if(nodeBIsInSet)
		{
			nodeAInSetLabel = i;//顶点所在集合索引		
			//nodeBIsInSet = i;
		}
	}

	//5：根据点所在集合的不同作出不同的处理
	if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
	{//AB两点都没有在任意集合
		vector<int> vec;
		vec.push_back(nodeAIndex);
		vec.push_back(nodeBIndex);
		nodeSets.push_back(vec);//将新集合放入集合数组
	}
	else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
	{//A点不在集合中，而B点已经在集合
	 //将A点放入B点所在的点集合
		nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
	{//B点不在集合中，而B点已经在集合中
	 //将B点放入A点所在集合
		nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
	}
	else if(nodeAInSetLabel != -1 && nodeAInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)
	{//AB两点在不同的集合
	 //将B点放入A点所在集合，并将B点在原来所在集合中删除
		mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
		for(int k = nodeBInSetLabel;k < (int)nodeSets.size()-1;k++)
		{
			nodeSets[k] = nodeSets[k+1];
		}
	}
	else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
	{//AB两点在同一集合
		continue;
	}
	m_pEdge[edgeCount] = edgeVec[minEdgeIndex];//将最小权值边放入边集合
	edgeCount++;

	cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";
	cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;

	}
}

bool CMap::isInSet(vector<int> nodeSet,int target)
{
	for(int i = 0;i < nodeSet.size();i++)
	{
		if(nodeSet[i] == target)
		{
			return true;
		}
	}

	return false;
}

void CMap::mergeNodeSet(vector<int>& nodeSetA,vector<int> nodeSetB)
{
	for(int i = 0;i < nodeSetB.size();i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}
#endif
