/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：obj_exception.h
*   创 建 者：pengtangtang
*   创建日期：2019年12月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _OBJ_EXCEPTION_H
#define _OBJ_EXCEPTION_H

#include <iostream>
using namespace std;

class bad_hmean//接收异常的类
{
	public:
		bad_hmean(double a = 0,double b = 0):v1(a),v2(b) {}
		void mesg();//若有异常就抛出异常（当两个数互为相反数时就抛出）
	private:
		double v1;
		double v2;
};

inline void bad_hmean::mesg()
{
	if(v1 = -v2)
	{
		cout << "invalid arguments: a = -b\n";		
	}
}

class bad_g_mean
{
	public:
		double v1;
		double v2;
		bad_g_mean(double a = 0,double b = 0):v1(a),v2(b) {}
		const char* mesg();
};

inline const char*bad_g_mean::mesg()//当其中有一个数为负数时
{
	return "gmean() arguments should be >= 0\n";
}

#endif
