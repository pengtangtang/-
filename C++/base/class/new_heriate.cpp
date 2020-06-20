/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：new_heriate.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "new_heriate.h"
#include <cstring>

baseDMA::baseDMA(const char* l,int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label,l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy(label,rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete [] label;
}

baseDMA& baseDMA::operator = (const baseDMA& rs)
{
	if(this == &rs)
		return *this;
	delete [] label;
	label = new char[strlen(rs.label) + 1];
	strcpy(label,rs.label);
	rating = rs.rating;
	return *this;
	
}
		
std::ostream& operator << (std::ostream& os,const baseDMA& rs)
{
	os << "Lable:" << rs.label << endl;
	os << "Rating:" << rs.rating << endl;
	return os;
}
	
lackDMA::lackDMA(const char* c,const char *l,int r):baseDMA(l,r)
{
	strncpy(color,c,39);
	color[39] = '\0'; 
}
		
lackDMA::lackDMA(const char* c,const baseDMA& rs):baseDMA(rs)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1] = '\0';
}

std::ostream& operator << (std::ostream& os,const lackDMA& rs)
{
	os << (const baseDMA&)rs;
	os << "COlor:" << rs.color << endl;
	return os;
}

hasDMA::hasDMA(const char* s,const char* l,int r):baseDMA(l,r)
{
	style = new char[strlen(s) + 1];
	strcpy(style,s);
}

hasDMA::hasDMA(const char *s ,const baseDMA & rs):baseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy(style,s);
	
}

hasDMA::hasDMA(const hasDMA& rs):baseDMA(rs)
{
	style = new char[strlen(rs.style) + 1];
	strcpy(style,rs.style);

}
		
hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA& hasDMA::operator = (const hasDMA& rs)
{
	if(this == &rs)
		return *this;
	baseDMA::operator=(rs);
	delete [] style;
	style = new char[strlen(rs.style) + 1];
	strcpy(style,rs.style);
	return *this;
	
	
}
		
std::ostream& operator << (ostream& os,const hasDMA& rm)
{
	os << (const baseDMA&)rm;
	os << "Style:" << rm.style << endl;
	return os;
}
