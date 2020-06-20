/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：slist-test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <slist>// 需要配置其他配件
#include <algorithm>

int main()
{
	int i;
	slist<int> islist;
	cout << "size = " << islist.size() << endl;
	islist.push_front(9);
	islist.push_front(1);
	islist.push_front(2);
	islist.push_front(3);
	islist.push_front(4);
	cout << "size = " << islist.size() << endl;

	slist<int>::iterator ite = islist.begin();
	slist<int>::iterator ite2 = islist.end();
	for(;ite != ite2;++ite)
		cout << *ite << ' ';
	cout << endl;

	ite = find(islist.begin(),islist.end(),1);
	if (ite != 0)
		islist.insert(ite,99);

	cout << "size = " << islist.size() << endl;
	cout << *ite << endl;

	ite = islist.begin();
	ite2 = islist.end();
	for(;ite != ite2;++ite)
		cout << *ite << ' ';
	cout << endl;
	ite = find(islist.begin(),islist.end(),3);
	if (ite != 0)
		cout << *(islist.erase(ite)) << endl;


	ite = islist.begin();
	ite2 = islist.end();
	for(;ite != ite2;++ite)
		cout << *ite << ' ';
	cout << endl;

	return 0;
}
