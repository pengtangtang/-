/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：union_q.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstdio>

union myun
{
	struct { int x;int y;int z; }u;
	int k;
}a;

int main()
{
	a.u.x = 4;
	a.u.y = 5;
	a.u.z = 6;
	a.k = 1;
	printf("%d %d %d %d\n",a.u.x,a.u.y,a.u.z,a.k);
	return 0;
}
