/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：randwalk.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月16日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <fstream>


int main()
{
	ofstream fout;
	fout.open("thewalk.txt");
	using VECTOR::Vector;
	/*time()函数返回当前时间，通常为从某一个日期开始的秒数（广义地，time()接受time_t变量的地址，将时间放到变量中并返回它。将0作为地址参数，可以省略time_t变量声明）*/
	srand(time(0));/*设置随机数*/
	double direction;
	Vector step;/*内循环每轮新的方向*/
	Vector result(0.0,0.0);/*记录行走者的前进情况*/
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "enter target distance (q to quit): ";

	while(cin >> target)/*输入一共想走的距离*/
	{
		cout << "enter step length: ";
		if(!(cin >> dstep))/*每步走多远*/
			break;

		while(result.magval() < target)/*距离小于想走的距离*/
		{
			direction = rand() % 360;/*每一次走的方向是随机的*/
			step.reset(dstep,direction,Vector::POL);/*为矢量设置新的长度 方向 模式*/
			result = result+step;/*调用重载运算符+*/
			steps++;/*记录一共走了多少次*/
		}

		fout << "after " << steps << " steps,the subject has the following location:\n";
		fout << result << endl;
		result.polar_mode();/*从新设置模式*/
		fout << " or\n" << result << endl;
		fout << "average outward distance per step = " 
			<< result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout << "enter distance (q to quit): ";
	}

	cout << "buy\n";
	cin.clear();
	while(cin.get() != '\n')
		continue;
	return 0;
}

