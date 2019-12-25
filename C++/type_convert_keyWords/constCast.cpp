/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：constCast.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

void change(const int* pt,int n);
void ConstTest1();
void ConstTest2();

int main()
{
	#if 0
	const int constant = 21;
	const int* const_p = &constant;
	int* modifier = const_cast<int*>(const_p);
	*modifier = 7;
	cout << "constant = " << constant << endl;
	int pop1 = 38333;
	const int pop2 = 2000;
	const int* p = &pop2;
	int *q = const_cast<int *>(p);
	*q  = -103;
	cout << "pop2 = " << pop2 << endl;

	cout << "pop1,pop2: " << pop1 << ',' << pop2 << endl;
	change(&pop1,-103);
	change(&pop2,-103);
	cout << "pop1,pop2: " << pop1 << ',' << pop2 << endl;
#else
	ConstTest1();
	ConstTest2();

#endif
	return 0;
}
void change(const int* pt,int n)
{
	int * pc;
	pc = const_cast<int *>(pt);
	*pc += n;
}
void ConstTest1()
{
	const int a = 5;
	int* p;
	p = const_cast<int *>(&a);
	(*p)++;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;
}
void ConstTest2()
{
	int i ;
	cout << "please input a integer:";
	cin >> i;
	const int a = i;
	int &r = const_cast<int&>(a);
	r++;
	cout << a << endl;
}
