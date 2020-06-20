/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：queue.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月31日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
#include "queue.h"

Queue::Queue(int qs):qsize(qs)
{
	front = rear = NULL;	
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

bool Queue::enqueue(const Item& item)
{
	if(isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if(front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::dequeue(Item& item)
{
	if(front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if(temp == 0)
		rear = NULL;
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand()%3+1;
	arrive = when;
}
