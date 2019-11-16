/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>

class A{
#define n 10
	private:
		int a;
		int b;
	public:
		float c;
		A(){
			c=6;
			printf("Base class:default constructor,c=%f\n",c);
		}
		~A(){
		printf("Base class:distructor\n");
		}

		virtual void fun(int a=1){
			printf("Base class:%d\n",a);
		}
};

class B:public A{
	public:
		B(){
		c=8;
		printf("Derived class:default constructor,c=%f\n",c);
		}
		~B(){
			printf("Derived class:distructor\n");
		}

		virtual void fun(int a=2,int b=2)//A的fun被隐藏
		{
			printf("Derived class:%d %d\n",a,b);
		}
		
};

class C:private A{

};

int main()
{
	B *b =  new B;
	A *a = b;
	C *c =new C;

	a->a = n+1;/*a是私有数据成员，只能在类内部调用*/
	b->a = n+2;
	c->c = 8.6;/*c为private derived obj,数据成员为只能在类内部调用*/

	a->fun();
	b->fun();
	b->fun(5,6);
	//a->fun(5,6);error:no maching func
	return 0;
}
