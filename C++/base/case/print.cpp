/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：print.cpp
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

int main(int argc,char const *argv[])
{

	int i,j,k,f;
	for (i = 1;i <=4;i++)
	{
		for (j = 1;j <= 30;j++)
			cout << " ";
		for (k = 1;k <= 8-2*i;k++)
			cout << " ";
		for (f = 1;f <= 2*i;f++)
			cout << '*';
		cout << endl;
	}
	for (i = 1;i <= 3;i++)
	{
		for (j = 1;j <= 30;j++)
			cout << " ";
		for (f = 1;f <= 7-2*i;f++)
			cout << '*';
		cout << endl;
	}

	system("pause");
	return 0;
}
