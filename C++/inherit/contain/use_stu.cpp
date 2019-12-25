/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：use_stu.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月24日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "student.h"


void set(Student& sa,int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = 
	{Student(quizzes),Student(quizzes),Student(quizzes)};

	int i;
	for(i = 0;i < pupils;i++)
	{
		set(ada[i],quizzes);
	}
	cout << "Student list:\n";

	for(i = 0;i < pupils;++i)
	{
		cout << endl << ada[i];
		cout << "\naverage: " << ada[i].Average() << endl;
	}

	cout << "Done\n";

	return 0;
}

void set(Student& sa,int n)
{
	cout << "please enter the student's name:";
	getline(cin,sa);

	cout << "please enter " << n << "quiz scores:\n";
	for(int i = 0;i < n;i++)
	{
		cin >> sa[i];
	}

	while(cin.get() != '\n')
		continue;
}
