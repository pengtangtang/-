/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hanio.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


void move(char A,char B);
void hanoi(int n,char A,char B,char C);

int main()
{
	cout << "-----------\n";
	int disks;
	cin >> disks;
	hanoi(disks,'A','B','C');
	return 0;
}

void move(char A,char B)
{
	cout << A << "->" << B << endl;
}

void hanoi(int n,char A,char B,char C)
{
	if (1 == n)
		move(A,C);
	else
	{
		hanoi(n-1,A,C,B);
		move(A,C);
		hanoi(n-1,B,A,C);
	}
}
