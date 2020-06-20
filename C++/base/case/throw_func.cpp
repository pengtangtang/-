/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：throw_func.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

const int MAX = 3;
class Empty{};
class Full{};

class Stack{
	private:
		int s[MAX];
		int top;
	public:
		void push(int a);
		int pop();
		Stack() { top = -1; }
};

void Stack::push(int i)
{
	if (top >= MAX-1)
		throw Full();
	s[++top] = i;
}

int Stack::pop()
{
	if (top < 0)
		throw Empty();
	return s[top--];
}

int main()
{
	Stack s;
	try
	{
		s.push(1);
		cout << s.pop() << endl;
		cout << s.pop() << endl;
	}
	catch(Full) { cout << "Full()\n";}
	catch(Empty) { cout << "EMpty()\n";}
}
