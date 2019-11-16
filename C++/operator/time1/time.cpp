/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：time.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "time.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h,int m)
{
	hours = h;
	minutes = m;
}

void Time::add_min(int m)
{
	minutes += m;
	hours = minutes/60;
	minutes /= 60;
}

void Time::add_hr(int h)
{
	hours += h;
}

Time Time::sum(const Time& t) const
{
	Time t1;
	t1.minutes = minutes+t.minutes;
	t1.hours = hours+t.hours+t1.minutes/60;
	t1.minutes %= 60;
	return t1;
}

Time Time::operator +(const Time& t1)const
{
	Time t;
	t.minutes = minutes+t1.minutes;
	t.hours = hours+t1.hours+t.minutes/60;
	t.minutes %= 60;
	return t;
}

Time Time::operator -(const Time& t1)const
{
	Time diff;
	int tot1,tot2;
	tot1 = t1.minutes+60*t1.hours;
	tot2 = minutes+60*hours;
	diff.minutes = (tot2-tot1)%60;
	diff.hours = (tot2-tot1)/60;
	return diff;
}
Time Time::operator *(double mult)const
{
	Time diff;
	long tminutes=minutes*mult + hours*60*mult;
	diff.hours = tminutes/60;
	diff.minutes = tminutes%60;
	return diff;
}
void Time::show() const
{
	cout << hours << " hourse, " << minutes << "minutes\n";
}
#if 0
Time operator *(double m,const Time& t)
{
	Time diff;
	long tminutes=t.minutes*m + t.hours*60*m;
	diff.hours = tminutes/60;
	diff.minutes = tminutes%60;
	return diff;
}
#else
Time operator *(double m,const Time& t)
{
	return t*m;
}

ostream& operator << (ostream &so,const Time &t)
{
	so << t.hours << " hours, " << t.minutes << " minutes\n";
	return so;
}



#endif
