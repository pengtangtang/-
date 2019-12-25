/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：worker.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "worker.h"

Worker::~Worker() {}

void Worker::set()
{
	cout << "enter worker's name : ";
	getline(cin,fullname);
	cout << "enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}

void Worker::show() const
{
	cout << "Name: " << fullname << endl;
	cout << "id: " << id << endl;
}

void Waiter::set()
{
	Worker::set();
	cout << "enter waiter's panache rating: ";
	cin >> panache;
	while(cin.get() != '\n')
		continue;
}

void Waiter::show() const
{
	Worker::show();
	cout << "panache rating : " << panache << "\n";
}


char* Singer::pv[] = {"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::set()
{
	Worker::set();
	cout << "Enter number for singer's vocal range：\n";

	int i;
	for(i = 0;i < Vtypes;i++)
	{
		cout << i << ": " << pv[i] << " ";
		if(i%4 == 3)
			cout << endl;
	}
	if(i%4 != 0)
		cout << endl;
	while(cin >> voice && (voice < 0 || voice > Vtypes))
		cout << "please enter a value >= 0 and < " << Vtypes << endl;

	while(cin.get() != '\n')
		continue;
}

void Singer::show() const
{
	cout << "category :singer\n";
	Worker::show();
	cout << "vocal range: " << pv[voice] << endl;
}
