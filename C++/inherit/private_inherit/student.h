/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：student.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
#include <string>
#include <valarray>
using namespace std;
/*
 *1:初始化基类组建
    使用成员初始化列表，使用类名而非成员名标识构造函数

  2：访问基类的方法
    使用类名和作用域解析运算符调用基类的方法

  3：访问基类对象
     使用强制类型转换。
eg:由于Student类是从string类派生出来，则可以通过强制类型转换，将Student对象转换为string对象，结果为继承而来的string对象
 *this为用来调用方法的对象
 * */
class Student:private string,private valarray<double>
{
	private:
		typedef valarray<double> ArrayDb;
		ostream& arr_out(ostream& os) const;
	public:
		Student():string("Null"),ArrayDb() {}
		/*可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数
		 * 若没有explicit修饰构造函数，则Student doh("homer",10); doh = 5;将调用Student(5)将5转换为一个临时对象*/
		explicit Student(const string& s):string(s),ArrayDb() {}
		explicit Student(int n):string("Nully"),ArrayDb(n) {}
		Student(const string& s,int n):string(s),ArrayDb(n) {}
		Student(const string& s,const ArrayDb& a):string(s),ArrayDb(a) {}
		Student(const char *str,const double *pd,int n):string(str),ArrayDb(pd,n) {}
		~Student() {}

		double Average() const;
		const string& Name() const;
		double& operator[] (int i);
		double operator[] (int i) const;

		friend istream& operator >> (istream& is,Student& stu);
		friend istream& getline (istream& is,Student& stu);
		friend ostream& operator << (ostream& os,const Student& stu);

};

#endif
