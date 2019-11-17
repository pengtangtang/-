/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：rand_walk.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "vector.h"
#include <fstream>

int main()
{
	ofstream fcout;
	fcout.open("walkresult.txt");

	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned int steps = 0;
	double target;
	double dstep;

	cout << "enter target distance (q to quit):";
	
	while(cin >> target){
		cout  << "enter step length:";
		if(!(cin >> dstep))
			break;
		while(result.magval() < target){
			direction = rand()%360;
			step.reset(dstep,direction,Vector::POL);
			result = result + step;
			steps++;
		}
	fcout << "after " << steps << "steps,the subject has the fallowing location " << result << endl;
	result.polar_mode();
	fcout << "or\n";
	fcout << result << endl;
	fcout << "average outward distance per step = " << result.magval()/steps << endl;
	steps = 0;
	result.reset(0.0,0.0);
	cout << "enter target distance (q to quit):";
	}

	cout << "Buy!\n";
	cin.clear();
	while(!cin.get())
		continue;

	return 0;
}
