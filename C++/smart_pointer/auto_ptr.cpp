/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：auto_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <memory>
#include <string>



int main()
{
#if 0
	auto_ptr<string> films[5] = 
	{
		auto_ptr<string> (new string("one dong")),
		auto_ptr<string> (new string("two dong")),
		auto_ptr<string> (new string("three dong")),
		auto_ptr<string> (new string("four dong")),
		auto_ptr<string> (new string("five dong"))
	};
	auto_ptr<string> pwine;
	pwine = films[2];//error:films[2]已经转让所有权，此时films[2]是一个空指针


	cout << "the best baseball film are:\n";
	for(int i = 0;i < 5;i++)
		cout << *films[i] << endl;//当打印*films[2]时出现错误，因为此时它已经失去了所有权，是一个空指针。
	cout << "the winer is "<< *pwine << endl;
#else
	shared_ptr<string> films[5] = 
	{
		shared_ptr<string> (new string("one dong")),
		shared_ptr<string> (new string("two dong")),
		shared_ptr<string> (new string("three dong")),
		shared_ptr<string> (new string("four dong")),
		shared_ptr<string> (new string("five dong"))
	};
	shared_ptr<string> pwine;
	pwine = films[2];

	cout << "the best baseball film are:\n";
	for(int i = 0;i < 5;i++)
		cout << *films[i] << endl;
#endif
	cin.get();

	return 0;
}
