/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test_new_heriate.cpp
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

int main()
{
	baseDMA shirt("Portabelly",8);
	lackDMA balloon("red","Blimpo",4);
	hasDMA map("Mercator","buffalo keys",5);
	cout << "Display baseDMA object:\n";
	cout << shirt << endl;
	cout << "Display lackDMA object:\n";
	cout << balloon << endl;
	cout << "Display hasDMA object:\n";

	cout << map << endl;

	lackDMA balloon2(balloon);
	cout << "result of lackDMA copy:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;

	cout << map2 << endl;
	return 0;
}
