/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：9.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月21日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <iostream>
#include "golf.h"
#include <cstring>

using namespace std;
void other();

namespace n1
{
	int x = 1;
}

namespace n2
{
	int x = 2;
}

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
#if 1
	chaff* ch = new chaff[2];
	cout << "init struct:";

	strcpy(ch[0].dross,"hello");
	ch[0].slag = 0;
	strcpy(ch[1].dross,"hi");
	ch[0].slag = 1;

	for(int i = 0;i < 2;i++)
	{
		cout << "dross:" << ch[i].dross
			<< ",slag:" << ch[i].slag << endl;
	}
#else
	cout << "please input golf user:";
	int sum;
	cin >> sum;
	golf *g = new golf[sum];
	int i = 0;
	while(i < sum )
	{
		if(!setgolf(g[i]))
		{
			cout << i << " input faile!\n";
		}
		if(!g[i].fullname) 
		{
			break;
		}
		i++;

	}
	
	for(int i = 0;i < sum;i++)
	{
		showgolf(g[i]);
	}

	golf ann;
	setgolf(ann,"hrllo",2);

	showgolf(ann);
	cin.get();
	cin.clear();

	using namespace n1;
	cout << x << endl;

	{
		int x = 4;
		cout << x << "," << n1::x << "," <<n2::x << endl;
	}

	using n2::x;
	cout << x << endl;

	other();

	using std::cout;
	using std::cin;
	using std::endl;
	double x;
	cout << "Enter value:";

	while(!(cin >> x))
	{
		cout << "Bad input.Please enter a number:";
		cin.clear();
		while((cin.get()) != '\n')
			continue;
	}

	cout << "Value = " << x << endl;
#endif
	return 0;
}

void other()
{
	using namespace n2;
	cout << x << endl;
	{
		int x = 4;
		cout << x << "," << n1::x << "," << n2::x << endl;
	}
	using n2::x;
	cout << x << endl;
}
