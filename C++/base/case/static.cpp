/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：static.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int i = 1;

int main()
{
	static int a;
	int b = 10;
	int c = 0;
	void other(void);

	cout << "----NIM---\n";
	cout << "i : " << i << "a: " << a << "b: " << b << " c: " << c << endl;
	c += 8;
	other();
	cout << "i : " << i << "a: " << a << "b: " << b << " c: " << c << endl;
	i += 10;
	other();

	return 0;
}

void other()
{
	static int a = 2;
	static int b;
	int c = 10;
	a += 2;
	i += 32;
	c +=5;
	cout << "i = " << i << " a = " << a << " b = " << b << " c = " << c << endl;
	b= a;
}
