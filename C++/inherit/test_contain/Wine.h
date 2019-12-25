/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：Wine.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _WINE_H
#define _WINE_H

#include <string>
#include <valarray>

typedef valarray<int> ArrayInt;
typedef pair<ArrayInt,ArrayInt> PairWine;

class Wine{
	public:
		Wine(const char* l,int y,const int yr[],const int bot[]);
		Wine(const char* l,int y);
		void GetBottles();
		void Show() const;
		const string& Lable();
		int Sum();
	private:
		int y_number;
		string lable;
		PairWine MyWine;
};

#endif
