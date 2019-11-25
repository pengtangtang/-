/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：ptr_static.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "ptr_static.h"
#include <cstdlib>
#include <ctime>

const int Num = 10;

int main()
{
	srand(time(0));
	cout << "please enter stack size:";
	int stacksize;
	cin >> stacksize;
	Stack<const char*> st(stacksize);

	const char *in[Num] = {
		"1:hank gilgamesh","2:kiki ishtar","3:betty rocker","4:ian flagrant",
		"5:wolfgang kibbla","6：port koop","7:joy almo","8:xaver papr","9:juan morre",
		"10:misha mache"
	};

	const char *out[Num];

	int processed = 0;
	int nextin = 0;
	/*模拟随机处理文件：未处理文件in 已经处理的文件out 待处理文件st*/
	while(processed < Num)
	{
		if(st.isempty())
			st.push(in[nextin++]);
		else if(st.isfull())
			st.pop(out[processed++]);
		else if(rand()%2 && nextin<Num)/*由0 1来决定是处理文件还是取文件*/
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}

	for(int i=0;i<Num;i++)
		cout << out[i] << endl;
	cout << "Buy!\n";

	return 0;
}
