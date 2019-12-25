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

/*1:初始化被包含的成员对象
 * 使用初始化列表来初始化成员对象
 *
 * 2：使用被包含对象的接口
 * 通过对象调用方法的形式
 *
 * */

class Student{
	private:
		typedef valarray<double> ArrayDb;
		string name;
		ArrayDb scores;
		ostream& arr_out(ostream& os) const;
	public:
		Student():name("Null"),scores() {}
		/*可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数
		 * 若没有explicit修饰构造函数，则Student doh("homer",10); doh = 5;将调用Student(5)将5转换为一个临时对象*/
		explicit Student(const string& s):name(s),scores() {}
		explicit Student(int n):name("Nully"),scores(n) {}
		Student(const string& s,int n):name(s),scores(n) {}
		Student(const string& s,const ArrayDb& a):name(s),scores(a) {}
		Student(const char *str,const double *pd,int n):name(str),scores(pd,n) {}
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
