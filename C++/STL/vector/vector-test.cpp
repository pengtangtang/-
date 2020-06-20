/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   i
*   文件名称：vector-test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int i;
	vector<int> iv(2,9);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	iv.push_back(1);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	iv.push_back(2);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	iv.push_back(3);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	iv.push_back(4);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	for (i = 0;i < iv.size();i++)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;

	iv.push_back(5);

	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	for (i = 0;i < iv.size();i++)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;

	iv.pop_back();
	iv.pop_back();

	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	vector<int>::iterator ivit = find(iv.begin(),iv.end(),i);
	if (ivit != iv.end()) iv.erase(ivit);

	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	for (i = 0;i < iv.size();i++)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;

	ivit = find(iv.begin(),iv.end(),2);
	if (ivit != iv.end()) iv.insert(ivit,3,7);

	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	for (int i = 0;i < iv.size();i++)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;

	iv.clear();
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;

	return 0;
}
