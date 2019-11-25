/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：array.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _ARRAY_H
#define _ARRAY_H

#include <cstdlib>
#include <iostream>

template<class T,int n>
class Array{
	public:
		Array(){};
		explicit Array(const T &v);
		virtual T& operator[](int i);
		virtual T operator[](int i)const;
	private:
		T ar[n];
};

template<class T,int n>
Array<T,n>::Array(const T &v)
{
	for(int i=0;i<n;i++)
		ar[i] = v;
}

template<class T,int n>
T& Array<T,n>::operator [](int i)
{
	if(i<0 || i>=n)
	{
		cout << "out of size:" << i;
		exit(-1);
	}
	return ar[i];
}

template<class T,int n>
T Array<T,n>::operator [](int i) const
{
	if(i<0 || i>=n)
	{
		cout << "out of size:" << i;
		exit(-1);
	}
	return ar[i];
}


#endif
