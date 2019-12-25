/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：sales.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "sales.h"

Sales::bad_index::bad_index(int ix,const string& s)
	:logic_error(s),bi(ix)//初始化logic_error()与bi
{}

Sales::Sales(int yy)//初始化数据成员，月份采用默认值
{
	year = yy;
	for(int i = 0;i < MONTHS;++i)
		gross[i] = 0;
}

Sales::Sales(int yy,const double* gr,int n)//自定义月份
{
	year = yy;
	int lim = (n < MONTHS ? n : MONTHS);
	int i;
	for(i = 0;i < lim;i++)
		gross[i] = gr[i];
	for(;i < MONTHS;i++)
		gross[i] = 0;
}

double Sales::operator[] (int i) const
{
	if(i < 0 || i > MONTHS)
		throw bad_index(i);//抛出异常（给logic_error()和bi赋值）
	return gross[i];
}

double& Sales::operator[](int i)
{
	if(i < 0 || i > MONTHS)
		throw bad_index(i);
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string& lb,int ix,
		const string& s):Sales::bad_index(ix,s)//通过参数列表初始化基类对象
{
	lbl = lb;
}

LabeledSales::LabeledSales(const string& lb,int yy,const double* gr,int n)
	:Sales(yy,gr,n)//通过参数列表初始化基类对象
{
	label = lb;
}

double LabeledSales::operator[] (int i) const
{
	if(i < 0 || i > MONTHS)
		throw nbad_index(Label(),i);//抛出异常，实例化nbad_index-->实例化bad_index-->实例化logic_error
	return Sales::operator[](i);
}

double& LabeledSales::operator[](int i)
{
	if(i < 0 || i > MONTHS)
		throw nbad_index(Label(),i);
	return Sales::operator[](i);
}
