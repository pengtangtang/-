/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：Wine.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _WINE_H
#define _WINE_H

#include <valarray>
#include <string>

template<class T1,class T2>
class Pair
{
	public:
		T1& first();
		T2& second();
		T1 first()const { return a; } 
		T2 second()const { return b; }
		Pair(const T1& aval,const T2& bval):a(aval),b(bval){}
		Pair() {}
		Pair& operator = (const Pair& p);
	private:
		T1 a;
		T2 b;
};

template<class T1,class T2>
T1& Pair<T1,T2>::first()
{
	return a;
}

template<class T1,class T2>
T2& Pair<T1,T2>::second()
{
	return b;
}

template<class T1,class T2>
Pair<T1,T2>& Pair<T1,T2>::operator = (const Pair<T1,T2>& p)
{
	a = p.a;
	b = p.b;
	return *this;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine:private string,private PairArray
{
	public:
		Wine();
		Wine(const char* l,int y,const int yr[],const int bot[]);
		Wine(const char* l,int y);
		void GetBottles();
		void Show() const;
		const string& Label() const { return (const string&)*this; }
		int Sum() const;
	private:
		int years;
};

#endif
