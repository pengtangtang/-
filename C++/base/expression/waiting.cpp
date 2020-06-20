/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：waiting.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <ctime>

int main()
{
	cout << "enter the delay time,in seconds:";
	float secs;
	cin >> secs;
	//CLOCKS_PER_SEC--每秒中包含的系统时间单位数
	clock_t delay = secs*CLOCKS_PER_SEC;
	cout << "starting\n";
	clock_t start = clock();
	while(clock()-start < delay);
	cout << "done\n";
	return 0;
}
