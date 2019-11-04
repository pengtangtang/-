/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：queue.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class m_queue{
	public:
		m_queue(int f=0,int r=0,const int s=4):size(s),front(f),rear(r){}
		void push_queue(int data);
		int pop_queue();
		bool empty_queue();
	private:
		int *a;
		int size;
		int front;
		int rear;
};

void m_queue::push_queue(int data)
{
	if(empty_queue())
		return ;
	a[rear] = data;
	rear = (rear+1)%size;
}

int m_queue::pop_queue()
{
	int m = a[front];
	front = (front+1)%size;
	return m;
}

bool m_queue::empty_queue()
{
	return rear==front;
}


int main()
{
  	m_queue obj1;

}
