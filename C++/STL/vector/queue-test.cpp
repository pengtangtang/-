/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：queue-test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
	deque<int> ideq(20,9);
	cout << "size  = " << ideq.size() << endl;

	for (int i = 0;i < ideq.size();i++)
		ideq[i] = i;

	for (int i = 0;i <ideq.size();i++)
		cout << ideq[i] << ' ';
	cout << endl;

	for (int i = 0; i < 3;i++)
		ideq.push_back(i);

	for (int i = 0;i <ideq.size();i++)
		cout << ideq[i] << ' ';
	cout << endl;

	ideq.push_back(3);
	for (int i = 0;i <ideq.size();i++)
		cout << ideq[i] << ' ';
	cout << endl;

	ideq.push_front(3);
	for (int i = 0;i <ideq.size();i++)
		cout << ideq[i] << ' ';
	cout << endl;

	deque<int>::iterator itr;
	itr = find(ideq.begin(),ideq.end(),2);
	cout << *itr << endl;
	return 0;
}
