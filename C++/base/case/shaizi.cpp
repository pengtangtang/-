/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：shaizi.cpp
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

int rolldice();

int main()
{
	int flag;
	unsigned seed;
	cout << "---------\n";
	cin >> seed;
	srand(seed);

	int sum = rolldice();
	int selfdim;
	switch(sum)
	{
		case 7:
		case 11:
			flag = 1;
			break;
		case 2:
		case 3:
		case 12:
			flag = 2;
			break;
		default:
			flag = 0;
			selfdim = sum;
			break;
	}

	while (0 == flag)
	{
		sum = rolldice();
		if (sum == selfdim)
		{
			flag = 1;
		}
		else if (7 == sum)
		{
			flag = 2;	
		}
	}
	if (flag ==1)
	{
		cout << "player win\n";
	}
	else 
	{
		cout << "player loses\n";
	}
	return 0;
}

int rolldice()
{
	int sum = 0;
	int dim1 = rand()%6 + 1;
	int dim2 = rand()%6 + 1;
	sum = dim1 + dim2;
	cout << "sum = " << dim1 << " + " << dim2  << endl;
	return sum;
}
