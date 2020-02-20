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
#include "Coordinate.h"

class List{
public:
	List(int size);
	~List();

	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i,Coordinate* e);
	int LocateElem(Coordinate* e);

	bool PriorElem(Coordinate* currentElem,Coordinate* preElem);
	bool NextElem(Coordinate* currentElem,Coordinate* nextElem);


	void ListTraverse();

	bool ListInsert(int i,Coordinate* e);
	bool ListDelete(int i,Coordinate* e);
private:
	Coordinate* m_pList;
	int m_iSize;
	int m_iLength;
};
#endif
