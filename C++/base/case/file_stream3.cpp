/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_stream3.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>



class Employe{
	private:
		int number,age;
		char name[20];
		double sal;
	public:
		Employe() {}
		Employe(int num,char* Name,int Age,double Salary)
		{
			number = num;
			strcpy(name,Name);
			age = Age;
			sal = Salary;
		}
		void display()
		{ cout << number << '\t' << name << '\t' << age << '\t' << sal << endl;}
};

int main()
{
	ofstream out("./tt.dat",ios::out);
	Employe e1(1,"pp",23,2320);
	Employe e2(2,"pp",23,2320);
	Employe e3(3,"pp",23,2320);
	Employe e4(4,"pp",23,2320);

	out.write((char *)&e1,sizeof(e1));
	out.write((char *)&e2,sizeof(e2));
	out.write((char *)&e3,sizeof(e3));
	out.write((char *)&e4,sizeof(e4));

	Employe e5(3,"aa",40,2220);
	out.seekp(3*sizeof(e1));
	out.write((char*)&e5,sizeof(e5));
	out.close();

	vector<Employe> v;
	ifstream in("./tt.dat",ios::in | ios::binary);
	Employe p;
	in.read((char*)&p,sizeof(p));
	while (!in.eof())
	{
		v.push_back(p);
		in.read((char*)&p,sizeof(p));
	
	}
	in.close();
	vector<Employe>::iterator pos;
	pos = v.begin();
	for(pos = v.begin();pos != v.end();pos++)
		(*pos).display();

}
