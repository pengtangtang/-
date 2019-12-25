/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：student.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "student.h"

double Student::Average() const
{
	if(scores.size() > 0)
		return scores.sum();
	else
		return 0;
}

const string& Student::Name() const
{
	return name;
}

double& Student::operator[] (int i)
{
	return scores[i];
}

double Student::operator[](int i) const
{
	return scores[i];
}

ostream& Student::arr_out(ostream& os) const
{
	int i;
	int lim = scores.size();
	if(lim > 0)
	{
		for(i = 0;i < lim;i++)
		{
			os << scores[i] << " ";
			if(i%5 == 4)
				os << endl;
		}
		if(i%5 != 0)
			os << endl;
	}
}

istream& operator >> (istream& is,Student &stu)
{
	is >> stu.name;
	return is;
}

istream& getline(istream& is,Student& stu)
{
	getline(is,stu.name);
	return is;
}

ostream& operator << (ostream& os,const Student& stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.arr_out(os);
	return os;
}



