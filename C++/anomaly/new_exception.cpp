/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：new_exception.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <new>
#include <cstdlib>

struct Big{
	double stuff[20000];
};

int main()
{
	Big* pb;
	try{
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[10000];//若失败会抛出异常
		cout << "Got past the new request:\n";
	}
	catch(bad_alloc& ba)//由new引发的异常类bad_alloc
	{
		cout << "Caught the execption\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete [] pb;
	//空指针和new（编译器提供一个开关），让用户选择所需行为
	Big *pc;
	pc = new (std::nothrow) Big[20000];
	if(0 == pc)
	{
		cout << "Could not allocate memory.Buy\n";
		exit(EXIT_FAILURE);
	}
	return 0;
}
