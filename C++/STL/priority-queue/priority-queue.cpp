/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：priority-queue.cpp
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
#include <queue>

int main()
{
	int ia[9] = {1,2,3,4,5,6,7,8,9};
	priority_queue<int> ipq(ia,ia+9);
	cout << "size = " << ipq.size() << endl;

	for (int i = 0;i < ipq.size();i++)
		cout << ipq.top() << ' ';
	cout << endl;

	while (!ipq.empty())
	{
		cout << ipq.top() << ' ';
		ipq.pop();
	}
	cout << endl;

}
