/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：list-test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int i;
	list<int> ilist;
	cout << "size = " << ilist.size() << endl;

	ilist.push_back(0);
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);
	ilist.push_back(4);

	cout << "size = " << ilist.size() << endl;

	list<int>::iterator its;
	for (its = ilist.begin();its != ilist.end();its++)
		cout << *its << ' ';
	cout << endl;

	its = find(ilist.begin(),ilist.end(),3);
	if (its != ilist.end())
		ilist.insert(its,99);

	cout << "size = " << ilist.size() << endl;
	cout << *its << endl;
	for (its = ilist.begin();its != ilist.end();its++)
		cout << *its << ' ';
	cout << endl;
	its = find(ilist.begin(),ilist.end(),1);
	if (its != ilist.end())
		cout << *(ilist.erase(its)) << endl;

	for (its  = ilist.begin();its != ilist.end();its++)
		cout << *its << ' ';
	cout << endl;

	its = find(ilist.begin(),ilist.end(),99);
	int iv[5] = {4,5,6,7,7};
	list<int> ilist2(iv,iv+5);
	ilist.splice(its,ilist2);
	for (its = ilist.begin();its != ilist.end();its++)
		cout << *its << ' ';
	cout << endl;
	ilist.reverse();
	ilist.sort();
	return 0;
}
