/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：getline.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
#if 1
	char stu[5][10];
	for (int i = 0;i < 5;i++)
		cin.getline(stu[i],10,',');
	for (int i = 0;i < 5;i++)
		cout << stu[i] << endl;
#else
	char e[10];
	cin.get(e,8,',');
	cout << e << endl;

	char c = cin.get();

	char e1[10];
	char f1;
	cin.getline(e1,10,',');
	cin.get(f1);
	cout << e1 << endl << f1 << endl;
	return 0;
#endif
}
