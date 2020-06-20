/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test_string.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "String.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	String name;
	cout << "HI,what's your name?\n";
	cin >> name;

	cout << name << ",please enter up to " << ArSize 
		<< " short sayings<empty line to quit>\n";

	String sayings[ArSize];
	char temp[MaxLen];

	int i;
	for(i = 0;i < ArSize;i++)
	{
		cout << i+1 << ": ";
		cin.get(temp,MaxLen);
		while(cin && cin.get() != '\n')
			continue;
		if(!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if(total > 0)
	{
		cout << "Here are your sayings:\n";
		for(i = 0;i < total;i++)
		{
			cout << sayings[i][0] << ":" << sayings[i] << endl;
		}

		int shortest = 0;
		int first = 0;
		for(i = 1;i < total;i++)
		{
			if(sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if(sayings[i] < sayings[first])
				first = i;
		}

		cout << "shortest saying:\n" << sayings[shortest] << endl;
		cout << "first alphabetically:\n" << sayings[first] << endl;
		cout << "this program used " << String::HowMany()
			<< " string objects.\n";
	}
	else
		cout << "No input!\n";
	return 0;
}
