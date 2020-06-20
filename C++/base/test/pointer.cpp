/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：pointer.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
#if 1
	inflatable* ps = new inflatable;
	cout << "enter name of inflatable item:";
	cin.get(ps->name,20);
	cout << "enter volume of inflatable item:";
	cin >> (*ps).volume;
	cout << "enter price:";
	cin >> ps->price;

	cout << "name:" << ps->name << endl;
	cout << "volume:" << ps->volume << endl;
	cout << "price: " << ps->price << endl;

	delete ps;
#else
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and " << bird << endl;
	cout << "enter a kind of nimal :" ;
	cin >> animal;

	ps = animal;

	cout << ps << endl;
	cout << animal << " at " << (int *)animal << endl;

	cout << ps << " at " << (int *)ps << endl;

	ps = new char[strlen(animal)+1];
	strcpy(ps,animal);
	cout << "after using strcpy()\n";
	cout << animal << " at " << (int *)animal << endl;
	cout << ps << " at " << (int *)animal << endl;

	delete [] ps;

#endif
	return 0;
}
