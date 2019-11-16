/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：using_occasion.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#if 0
class Test1{
	public:
		Test1(){ cout << "Test1\n";}
		Test1(int a):i(a){
			cout << i << endl;
		}
	private:
		int i;
};

class Test2{
	public:
	Test1 test1;
	Test2(int x):test1(x){}/*初始化列表1*/
	Test2(Test1 &t1):test1(t1){}/*初始化列表2*/
};

int main()
{
	Test2 t2(2);
	Test1 t1;
	Test2 t3(t1);
	return 0;
}
#else

/*类成员为const或引用类型*/
class A{
	public:
		A(int &v):i(v),p(v),j(v){}
		void print_val()
		{
			cout << "i = " << i
				<< "j = " << j << endl;
		}
	private:
		const int i;
		int p;
		int &j;
};

/*类成员为没有默认构造函数的类类型*/

class Base{
	public:
		Base(int a):val(a){}
	private:
		int val;
};

class B{
	public:
		B(int v):p(v),b(v){};/*创建对象时要初始类成员的没一个成员*/
		void print_val()
		{
			cout << "p = " << p << endl;
		}
	private:
		int p;
		Base b;
};

/*如果类存在继承关系，派生类必须在其初始化列表中调用基类的构造函数*/

class Mbase{
public:
	Mbase(int a):val(a){}
private:
	int val;
};
class C:public Mbase{
public:
	C(int v):p(v),Mbase(v){}
	void print_val()
	{
		cout << "p = " << p << endl;
	}
private:
	int p;
};

int main()
{
	int pp = 12;
	A p(pp);
	p.print_val();
	B b(pp);
	b.print_val();
	C c(pp);
	c.print_val();
	return 0;
}

#endif
