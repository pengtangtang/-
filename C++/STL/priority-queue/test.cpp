/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>//含各容器的各种函数
#include <stack>


struct node 
{
	friend bool operator< (node n1,node n2)
	{
		return (n1.priority < n2.priority);
	}

	int priority;
	int value;
};

int main()
{
	const int len = 5;
	int a[len] = {3,5,9,6,2};

	cout << "---从大到小输出----\n";
	priority_queue<int> q1;
	for (int i = 0;i < len;i++)
		q1.push(a[i]);
	for (int i = 0;i < len;i++)
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	cout << "---从小到大输出----\n";
	priority_queue<int,vector<int>,greater<int> >q2;
	for (int i = 0;i < len;i++)
		q2.push(a[i]);
	for (int i = 0;i < len;i++)
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;

	cout << "---按优先级输出----\n";
	priority_queue<node> qn;
	node b[len];
	b[0].priority = 6;
	b[0].value = 1;
	b[1].priority = 9;
	b[1].value = 5;
	b[2].priority = 2;
	b[2].value = 3;
	b[3].priority = 8;
	b[3].value = 7;
	b[4].priority = 1;
	b[4].value = 4;

	for (int i = 0;i < len;i++)
		qn.push(b[i]);
	cout << "优先级" << '\t' << "值" << endl;
	for (int i = 0;i < len;i++)
	{
		cout << qn.top().priority << '\t' << qn.top().value << endl;
		qn.pop();
	}

	return 0;
}
