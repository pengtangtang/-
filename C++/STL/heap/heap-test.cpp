/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：heap-test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月04日
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
	int ia[9] = {0,1,2,3,4,5,8,9,8};
	vector<int> iec(ia,ia+9);

	make_heap(iec.begin(),iec.end());
	for (int i = 0;i < iec.size();i++)
		cout << iec[i] << ' ';
	cout << endl;

	iec.push_back(7);
	push_heap(iec.begin(),iec.end());
	for (int i = 0;i < iec.size();i++)
		cout << iec[i] << ' ';
	cout << endl;

	pop_heap(iec.begin(),iec.end());
	cout << iec.back() << endl;
	iec.pop_back();


	for (int i = 0;i < iec.size();i++)
		cout << iec[i] << ' ';
	cout << endl;

	sort_heap(iec.begin(),iec.end());
	for (int i = 0;i < iec.size();i++)
		cout << iec[i] << ' ';
	cout << endl;
	return 0;
}
