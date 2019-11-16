/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：volatile.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	int n = 10;
	volatile int a = n;
	volatile int b = n;

	return 0;
}
