/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_arr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#if 0
class exam{
	public:
		void set_x(int n){x = n;}
		int get_x(){return x;}
	private:
		int x;
};

int main()
{
	exam ob[4];
	int i;

	for(i=0;i<4;i++){
		ob[i].set_x(i);
	}
	for(i=0;i<4;i++){
		cout << ob[i].get_x() << " ";
	}
	cout << endl;
	return 0;
}
#else
class exam{
	public:
		exam(){x = 123;}
		exam(int n){x = n;}
		int get_x(){return x;}
	private:
		int x;
};

int main()
{
	exam ob1[4]={11,22,33,44};
	exam ob2[4]={55,66};
	exam ob3[4]={exam(11),exam(22),exam(33),exam(44)};
	exam ob4[4]={exam(55),exam(66)};
	ob4[2]=exam(77);
	ob4[3]=exam(88);

	int i;
	for(i=0;i<4;i++)
		cout << ob1[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob2[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob3[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob4[i].get_x() << ' ';
	cout << endl;
	return 0;
}

#endif
