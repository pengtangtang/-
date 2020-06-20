/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：set.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <set>

int main()
{
	int i = 0;
	set<int> set1;

	for (int i = 0;i < 10;i++)
		set1.insert(i);

	set<int>::iterator it;
	for (it = set1.begin();it != set1.end();it++)
		cout << *it << " ";
	cout << endl;

	set1.erase(5);
	if (set1.insert(3).second)
		cout << "success\n";
	else
		cout << "failed\n";

	set<int>::iterator itr;
	for (itr = set1.begin();itr != set1.end();itr++)
		cout << *itr << " " ;
	cout << endl;

	set1.clear();
	return 0;
}
