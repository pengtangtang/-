/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：10.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月30日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "m_10.h"


int main()
{
	Person one;
	Person two("Smythcraft");
	Person three("Dimwiddy","Sam");

	one.Show();
	one.FormalShow();
	two.Show();
	two.Show();
	three.FormalShow();
	three.FormalShow();

	return 0;
}
