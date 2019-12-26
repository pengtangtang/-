/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：c_to_c.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Char;
class Inherit{
	public:
		Integer(int num = 0) { val = num; }
		int getVal() { return val; }
		operator char() const;
	private:
		int val;
};

class Char{
	public:
		Char(char c = '\0') { var = c; }
		char getChar() { return var; }
		operator Integer() const { return Integer(var); }
	private:
		char var;
};

Integer::operator char() const
{
	return (char)val;
}
int main()
{
	Integer a(100);
	cout << a.getVal() << endl;

	Char c('c');
	cout << "c = " << c.getChar() << endl;

	a = c;//c隐调用转换函数operator Integer() const;
	cout << "a = " << a.getChar() << endl;
	return 0;
}
