/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：struct.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月28日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

#if 0
struct ADD{
	int x;
	int y;
};

int sum(int a,int b)
{
	return (a+b);
}

int main()
{
	ADD obj = {1,2};
	ADD obj1 = {
		x:1,
		y:2
	};

	cout << obj.x << endl;
	cout << obj1.y << endl;
	return 0;
}
#else
struct inflatable
{
	char name[20];
	float volume;
	double price;
};


int main()
{
#if 1
	inflatable guests[2] = 
	{
		{"bamb",0.5,21.99},
		{"god",2000,565.99}
	};

	cout << "The guest " << guests[0].name << " and " << guests[1].name
		<< "\nhanve a combined volume of " 
		<< guests[0].volume+guests[1].volume << " cubic feet.\n";
#else
	inflatable bouquet = 
	{
		"sunflowers",
		0.20,
		12.49
	};

	inflatable chioce;
	cout << "bouquet:" << bouquet.name << "for $";
	cout << bouquet.price << endl;
	chioce = bouquet;
	cout << "chioce:" << chioce.name << " for $";
	cout << chioce.price << endl;
	return 0;
#endif
}
#endif
