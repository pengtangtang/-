/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：initialization_list.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Test1{
	public:
		Test1()
		{cout << "Test1\n";}

		Test1(const Test1& t1)
		{
			cout << "Copy constructor for Test1\n";
			this->a = t1.a;
		}

		Test1& operator = (const Test1& t1)
		{
			cout << "assignment for Test1\n";
			this->a = t1.a;
			return *this;
		}

	private:
		int a;
};

class Test2{
	public:
	Test1 test1;
	Test2(Test1 &t1):test1(t1)/*等价于test1=t1调用赋值拷贝函数*/
	{}
};

int main()
{
	Test1 t1;
	Test2 t2(t1);/*为test1赋值*/
	return 0;
}
