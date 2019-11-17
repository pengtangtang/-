/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：memb_pt.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Example{
public:
	Example();
	Example(int ft);
	~Example();

	void show_in() const;
	void show_ft() const;
	void use_ptr() const;
private:
	int feet;
	int inches;
};

Example::Example()
{
	feet = 0;
	inches = 0;
}

Example::Example(int ft)
{
	feet = ft;
	inches = 12*feet;
}

Example::~Example()
{}

void Example::show_in() const
{
	cout << inches << "inches\n";
}

void Example::show_ft() const
{
	cout << feet << "feet\n";
}

void Example::use_ptr() const
{
	Example yard(3);
	int Example::*pt;/*声明数据成员指针相当于一个成员名
			   :指向数据成员在任意对象中的位置*/
	pt = &Example::inches;/*为数据成员指针赋值*/

	cout << "set pt to Example::inches:\n";
	cout << "this-<pt: " << this->*pt << endl;
	cout << "yard.*pt: " << yard.*pt << endl;

	void (Example::*pf)()const;/*成员函数指针*/
	pf = &Example::show_in;
	cout << "set pf to &Example::show_in\n";
	cout << "using (this->*pf)(): ";
	(this->*pf)();
	cout << "using (yard.*pf)(): ";
	(yard.*pf)();
}

int main()
{
	Example car(15);
	Example van(20);
	Example garage;

	cout << "car.use_ptr() output: \n";
	car.use_ptr();

	cout << "\n van.use_ptr() output:\n";
	van.use_ptr();

	return 0;
}
