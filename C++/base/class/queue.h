/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：queue.h
*   创 建 者：pengtangtang
*   创建日期：2020年03月31日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _QUEUE_H
#define _QUEUE_H

class Customer
{
	private:
		long arrive;
		int processtime;
	public:
		Customer() { arrive = processtime = 0; }
		void set(long when);
		long when() const { return arrive; }
		int ptime() const { return processtime; }
};


typedef Customer Item;

class Queue
{
	private:
		struct Node{Item item;struct Node* next; };
		enum {Q_SIZE = 10};
		Node* front;
		Node* rear;
		int items;
		const int qsize;
		Queue(const Queue& q):qsize(0){}
		Queue& operator = (const Queue& q) { return *this; }
	public:
		Queue(int qs =Q_SIZE);
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int queuecount() const;
		bool enqueue(const Item& item) ;
		bool dequeue(Item& item);
};

#endif
