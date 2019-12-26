# if 0
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
/*使用场景：*/
	/*1）为动态申请的资源提供异常安全保证。确保动态资源被释放。
	void func()
	{
		int* p = new int(5);
		//可能会抛出异常
		delete p;
	}
	void func()
	{
		unique_ptr<int> p(new int(5));
		//可能会抛出异常
	}*/
	//2）返回函数内动态申请资源的所有权
	unique_ptr<int> func(int p)
	{
		unique_ptr<int> p_int(new int(p));
		return p_int;
	}
	int main()
	{
		int p = 5;
		unique_ptr<int> ret = func(p);
		cout << *ret << endl;
		
	//3）在容器中保存指针
		vector<unique_ptr<int>> vec;
		unique_ptr<int> q(new int(5));
		vec.push_back(move(q));
	//4）管理动态数组
		unique_ptr<int []> p1(new int[5] {1,2,3,4,5});
		p1[0] = 0;
		cout << p1[0] << endl;

	}
#else
	//5）作为auto_ptr的替代品
#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;

struct foo{
	foo() { cout << "foo::foo\n"; }
	~foo() { cout << "foo::~foo\n"; }
	void bar() { cout << "foo::bar\n"; }
};

void f(const foo&)
{
	cout << "f(const foo&)\n";
}

struct d{
	void operator() (foo* fo)
	{
		cout << "d operator()\n";
		delete fo;
	}
};

void test_auto_destory()
{
	cout << "test_auto_destory----------------------\n";
	{
		unique_ptr<foo> p1(new foo);
	}

	{
		unique_ptr<foo[]> p2(new foo[4]);
	}
	{
		unique_ptr<foo,d> p3(new foo);
	}
}

void test_owner()
{
	cout << "test_owner--------------------------\n";
	unique_ptr<foo> p1(new foo);
	if(p1)  p1->bar();
	{
		unique_ptr<foo> p2(move(p1));
		f(*p2);

		p1 = move(p2);
		p2->bar();
		cout << "destory p2---\n";
	}
	p1->bar();
}

void test_array_owner()
{
	cout << "test_array_owner----------------\n";
	unique_ptr<foo[]> p1(new foo[4]);
	if(p1) p1[0].bar();
	{
		unique_ptr<foo[]> p2(move(p1));
		f(p2[0]);
		p1 = move(p2);
		p2[0].bar();
		cout << "destorying p2---------\n";
	}
	p1[0].bar();
}

int main()
{
	test_auto_destory();
	//test_owner();
	//test_array_owner();
	return 0;
}
#endif
