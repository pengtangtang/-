/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hashMain.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include "hash.h"

int main()
{
	vector<string> words{"java","c++","c","java","c#","python"};
	HashTable<string,int> ht(1);
	for (string word : words) {
		if (ht.contains(word))
			ht.set(word,ht.get(word)+1);
		else
			ht.add(word,1);
	}
	cout << ht;
	cout << "size = " << ht.getSize() << ",maxCapacity = "
		<< ht.maxCapacity() << " ,minCapacity = " << ht.minCapacity() << endl;
	string w = "c++";
	ht.remove(w);
	if (ht.contains(w))
		cout << w << ":" << ht.get(w) << endl;
	else
		cout << "no word" << w << "in words" << endl;

	cout << ht;

	ht.remove("c#");
	ht.remove("java");
	ht.remove("c");
	cout << "size = " << ht.getSize() << ",maxCapacity = "
		<< ht.maxCapacity() << " ,minCapacity = " << ht.minCapacity() << endl;
	cout << ht;

	map<string,int> m{{"a",1},{"b",2}};
	for (auto i:m) cout << i.first << " " << i.second << " ";
	cout << endl;

	m.insert(make_pair("a",2));
	for (auto i:m) cout << i.first << " " << i.second << " ";
	cout << endl;


	return 0;
}
