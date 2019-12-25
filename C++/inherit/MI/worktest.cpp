/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：worktest.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "worker.h"

const int LIM = 4;

int main()
{
	Waiter bob("bob apple",314L,5);
	Singer bev("Beverly Hils",522L,3);
	Waiter w_temp;
	Singer s_temp;

	SingerWaiter ed;
	Worker *pw = &ed;
	

	Worker *pv[LIM] = {&bob,&bev,&w_temp,&s_temp};

	int i;
	for(i = 2;i < LIM;i++)
		pv[i]->set();
	for(i = 0;i < LIM;i++)
	{
		pv[i]->show();
		cout << endl;
	}
	return 0;
}
