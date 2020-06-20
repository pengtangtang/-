/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_stream.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

class Person
{
	private:
		char name[20];
		char id[18];
		int age;
		char raddr[20];
	public:
		Person() {}
		Person(char *n,char *pid,int Age,char* Addr)
		{
			strcpy(name,n);
			strcpy(id,pid);
			strcpy(raddr,Addr);
			age = Age;
		}
		void display()
		{ cout << name << '\t' << id << '\t' << age << '\t' << raddr << endl; }
};

int main()
{
	vector<Person> v;
	vector<Person>::iterator pos;
	char ch;
	ofstream out("./test.dat",ios::out | ios::app | ios::binary);
	char Name[20],ID[18],Addr[20];
	int Age;

	cout << "-----------输入个人档案-------\n";
	do{
		cout << "name: ";
		cin >> Name;
		cout << "id: ";
		cin >> ID;
		cout << "age:";
		cin >> Age;
		cout << "addr: ";
		cin >> Addr;
		Person per(Name,ID,Age,Addr);
		out.write((char *)&per,sizeof(per));
		cout << "enter another person(y/n)?\n";
		cin >> ch;
	}while(ch == 'y');

	//cout << "after while\n";
	out.close();
	ifstream in("./test.dat",ios::in | ios::binary);
	Person s;
	in.read((char*)&s,sizeof(s));
	while (!in.eof())
	{
		v.push_back(s);
		in.read((char *)&s,sizeof(s));
	}

	cout << "\n---------read data from file\n";
	pos = v.begin();
	for (pos = v.begin();pos != v.end();pos++)
		(*pos).display();
	return 0;
}
