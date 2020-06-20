/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hash_test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月07日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include "hash.h"
#include <map>


int main()
{
	vector<string> words{"java","c++","c","python","java","c#","c"};
	HashTable<string,int> ht(1);
	for (string word : words)
	{
		if (ht.contains(word))
			ht.set(word,ht.get(word) + 1);
		else
			ht.add(word,1);
	}
	cout << ht;
	ht.remove("c#");
	ht.remove("java");

	cout << "size = " << ht.getSize() << endl;

	string w = "c++";
	ht.remove(w);
	if (ht.contains(w))
		cout << w << " : " << ht.get(w) << endl;
	else
		cout << "no word " << w << " in words" << endl;

}
