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

int main()
{

	Node node1,node2,node3,node4;
	node1.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;
	List* pList = new List();

	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node2);

	pList->ListInsertTail(&node4);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node1);
	pList->ListTraverse();

	delete pList;
	pList = NULL;
	return 0;
}
