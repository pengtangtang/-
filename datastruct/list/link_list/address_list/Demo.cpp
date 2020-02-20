/*
===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Demo.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "List.h"

/*线性表---通讯录
 * 联系人信息：姓名  电话
 *
 * bool InitList(List** list)
 * void DestroList(List* list)
 * void ClearList(List* list)
 * bool ListEmpty(List* list)
 * int ListLength(List* list)
 * bool GetElem(List** list,int i,Elem *e)
 * int LocateElem(List* list,Elem* e)
 * bool PriorElem(List* list,Elem* currentElem,Elem* preElem)
 * bool NextElem(List* list,Elem* currentElem,Elem* nextElem)
 * bool ListInsert(List* list,int i,Elem* e)
 * bool ListDelete(List* list,int i,Elem* e);
 * void ListTraverse(List* list)
 *
 * */
#if 1

int menu()
{
	cout << "******功能菜单******\n";
	cout << "    1-新建联系人    \n";
	cout << "    2-删除联系人    \n";
	cout << "    3-浏览通讯录    \n";
	cout << "    4-退出通讯录    \n\n\n";
	cout << "    请输入：    \n";

	int order = 0;

	cin >> order;
	return order;
}

void createPerson(List* pList)
{
	Node node;
	Person person;

	cout << "输入用户姓名：";
	cin >> person.name;

	cout << "输入用户电话号码：";
	cin >> person.phone;

	node.data = person;

	pList->ListInsertTail(&node);
}
#if 0
void deleteNode(List* pList,Node* node)
{
	Node* temp;
	temp->data = node->data;

	int i = pList->LocateElem(temp);

	if(!pList->ListDelete(i,temp))
	{
		cout << "delete faile\n";
	}
}
#else
void deletePerson(List* pList)
{
	Node node;
	Person person;
	cout << "请输入要删除用户的姓名:";
	cin >> person.name;
	cout << "请输入要删除用户的电话：";
	cin >> person.phone;

	node.data = person;

	int i = pList->LocateElem(&node);
	if(!pList->ListDelete(i,&node))
	{
		cout << "delete faile\n";
	}

}
#endif
int main()
{
	int userOrder = 0;
	List* pList = new List();

	while(userOrder != 4)
	{
		int flag = 0;
		userOrder = menu();

		switch(userOrder)
		{
			case 1:
				cout << "用户指令----》》新建联系人\n";
				createPerson(pList);
				break;
			case 2:
				cout << "用户指令----》》删除联系人\n";
				deletePerson(pList);
				break;
			case 3:
				cout << "用户指令----》》浏览通讯录\n";
				pList->ListTraverse();
				break;
			case 4:
				cout << "用户指令----》》退出通讯录\n";
				flag = 1;
				break;
		}

		if(flag)
		{
			break;
		}
	}

	delete pList;
	pList = NULL;
	return 0;
}

#else
int main()
{
	Node node1;
	Node node2;

	node1.data.name = "彭糖糖";
	node1.data.phone = "13628092682";

	node2.data.name = "彭风平";
	node2.data.phone = "15760085900";

	List* pList = new List();

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);

	pList->ListTraverse();
	return 0;
}
#endif
