/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：new_heriate.h
*   创 建 者：pengtangtang
*   创建日期：2020年04月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _NEW_HERIATE_H
#define _NEW_HERIATE_H
#include <iostream>

class baseDMA
{
	private:
		char* label;
		int rating;
	public:
		baseDMA(const char* l = "null",int r = 0);
		baseDMA(const baseDMA& rs);
		virtual ~baseDMA();
		baseDMA& operator = (const baseDMA& rs);
		friend std::ostream& operator << (std::ostream& os,const baseDMA& rs);
};

class lackDMA:public baseDMA
{
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		lackDMA(const char* c = "blank",const char *l = "null",int r = 0);
		lackDMA(const char* c,const baseDMA& rs);
		friend std::ostream& operator << (std::ostream& os,const lackDMA& rs);
};

class hasDMA:public baseDMA
{
	private:
		char* style;
	public:
		hasDMA(const char* s = "none",const char* l = "NULL",int r = 0);
		hasDMA(const char *s ,const baseDMA & rs);
		hasDMA(const hasDMA& rs);
		~hasDMA();
		hasDMA& operator = (const hasDMA& rs);
		friend std::ostream& operator << (ostream& os,const hasDMA& rm);
};

#endif
