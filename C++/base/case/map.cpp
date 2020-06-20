/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：map.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <map>
#include <string>

int main()
{
	string name[] = {"张三","里四","王二"};
	double salary[] = {1200,2000,1450};

	map<string,double> sal;
	map<string,double>::iterator p;
	for (int i = 0;i < 3;i++)
		sal.insert(make_pair(name[i],salary[i]));

	sal["tom"] = 6265;
	sal["bob"] = 5999;
	for (p = sal.begin();p != sal.end();p++)
		cout << p->first << '\t' << p->second << endl;

	string person;
	cout << "find person name:" ;
	cin >> person;
	int flag = 1;
	for (p = sal.begin();p != sal.end();p++)
	{
		if (p->first == person)
		{
			cout << p->second << endl;
			flag = 0;
		}
	}
	if (flag)
		cout << "no \n";

	cout << "there have\n";

	return 0;
}
