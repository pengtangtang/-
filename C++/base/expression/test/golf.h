/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：golf.h
*   创 建 者：pengtangtang
*   创建日期：2020年03月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _GOLF_H
#define _GOLF_H

const int len = 40;
struct golf
{
	char fullname[len];
	int handicap;
};

void setgolf(golf &g,const char* name,int hc);

int setgolf(golf &g);

void handicap(golf &g,int hc);

void showgolf(const golf &g);

#endif
