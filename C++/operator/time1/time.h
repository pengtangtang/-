/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：time.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _TIME_H
#define _TIME_H
#include <iostream>
class Time{
	public:
		Time();
		Time(int h,int m);
		void add_min(int m);
		void add_hr(int h);
		Time sum(const Time& t)const;
		Time operator + (const Time &t)const;
		Time operator - (const Time &t)const;
		Time operator * (double mult)const;
	//	friend Time operator * (double m,const Time &t);//const不能修饰类以外的函数
		/*注意：如果要为类重载运算符，并非将类的项作为其第一个参数则可以用友元函数来反转参数顺序*/
		void show()const;
	friend ostream& operator << (ostream &so,const Time &t);/*注意返回值,friend关键字只能在类声明中的原型使用，除非函数定义也是原型否则不能在函数定义处使用friend*/
	private:
		int hours;
		int minutes;
};
Time operator *(double m,const Time &t);
#endif

