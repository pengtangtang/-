/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：clock.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Time
{
	public:
		Time(int h = 0,int m = 0,int s = 0):hour(h),minute(m),second(s) {}
		void operator++();
		void operator()(int h,int m,int s);
		void showTime() { cout << "curent time:" << hour << ":" << minute << ":" << second << endl;}
	private:
		int hour,minute,second;
};

void Time::operator++()
{
	++second;

	if (60 == second)
	{
		second = 0;
		++minute;
		if (60 == minute)
		{
			minute = 0;
			++hour;
			if (24 == hour)
			{
				hour = 0;
			}
		}
	}
}

void Time::operator()(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

int main()
{
	Time t(23,59,59);
	++t;
	t.showTime();
	t.operator()(23,20,34);
	t.showTime();
	return 0;
}
