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
#include "List.h"
/*线性表---顺序表
 *3572918
 前驱 后继
 bool InitList(List** list)
 void DestroyList(List* list)
 bool ListEmpty(List* list)
 int ListLength(List* list)
 bool  GetElem(List* list,int i,Elem *e)
 int LocateElem(List* list)
 bool PriorElem(List* list,Elem* currenTElem,Elem* preElem)
 bool NextElem(List* list,Elem* currentElem,Elem* nextElem);
 bool ListInsert(List* list,int i,Elem* e)
 bool ListDelete(List* list,int i,Elem* e)
 void ListTraverse(List* list);
 * */

int main()
{
	List* list = new List(7);//显示调用

	Coordinate e1(3,5);
	Coordinate e2(4,5);
	Coordinate e3(6,8);
	Coordinate temp(0,0);

	list->ListInsert(0,&e1);
	list->ListInsert(1,&e2);
	list->ListInsert(2,&e3);
	list->ListTraverse();
	cout << endl;

	list->ListDelete(0,&temp);
	list->ListTraverse();
	cout << endl;


	int len = list->ListLength();
	cout << "len = " << len << endl;

	if(list->ListEmpty())
	{
		cout << "list is empty\n";
	}
	else
	{
		cout << "not empty\n";
	}

	list->ClearList();
	if(list->ListEmpty())
	{
		cout << "list is empty\n";
	}
	else
	{
		cout << "not empty\n";
	}
	list->ListTraverse();
	cout << endl;
	delete list;
	return 0;
}
