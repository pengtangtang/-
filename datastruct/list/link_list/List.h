/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：List.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LIST_H
#define _LIST_H
#include "Node.h"

class List{
public:
	List();
	~List();

	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i,Node* pNode);
	int LocateElem(Node* pNode);

	bool PriorElem(Node* pCurrentNode,Node* pPreNode);
	bool NextElem(Node* pCurrentNode,Node* pNextNode);


	void ListTraverse();

	bool ListInsert(int i,Node* pNode);
	bool ListDelete(int i,Node* pNode);

	bool ListInsertHead(Node* pNode);
	bool ListInsertTail(Node* pNode);
private:
	Node* m_pList;
	int m_iLength;
};
#endif
