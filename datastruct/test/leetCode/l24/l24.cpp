/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：l24.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "List.h"


class Solution{
	public:
		Node* reverseKGroup(Node* head,int k)
		{
			if(k == 1 || head == NULL)
				return head;

			Node* dummy = new Node();
			Node* Tail = dummy;
			Node* p = head;

			int count = 0;

			while(head)
			{
				count = 0;
				while((p != NULL) & (count < k))
				{
					p = p->next;
					count++;
				}
				if(k > count)
				{
					Tail->next = head;
					return dummy->next;
				}
				else
				{
					Tail->next = reversegroup(head,k);
					while(Tail->next != NULL)
						Tail = Tail->next;
					head = p;
				}
			}
			return dummy->next;
		}

		Node* reversegroup(Node* head,int k)
		{
			Node* cur;
			Node* tail;
			Node* ahead;

			tail = NULL;
			cur = NULL;
			ahead = head;

			int count = 1;

			while(count < k)
			{
				cur = head;
				ahead = cur->next;
				cur->next = tail;
				tail = cur;
				count++;
			}

			ahead->next = tail;
			return ahead;
		}
};

int main()
{
	List* pList = new List();
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();
	Node* node4 = new Node();

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	pList->ListInsertHead(node1);
	pList->ListInsertHead(node2);
	pList->ListInsertHead(node3);
	pList->ListInsertHead(node4);
	pList->ListInsertHead(node3);
	pList->ListInsertHead(node2);
	pList->ListInsertHead(node1);



	pList->ListTraverse();

	Node* head = new Node;
	head = pList->m_pList;
	
	Solution s;
	s.reverseKGroup(head,3);
	pList->ListTraverse();

	
}
