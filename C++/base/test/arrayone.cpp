/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：arrayone.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = {20,10,5};

	cout << "tatl yams = " << yams[0] + yams[1] + yams[2] 
		<< endl;
	cout << "the packsge with " << yams[1] << "yams costs " << yamcosts[1] << " cents per yam.\n";

	int tatal = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	cout << "\nsize of yams array = " << sizeof(yams) << "bytes" << endl;
	cout << "\nsize of yamcosts array = " << sizeof(yamcosts) << "bytes" << endl;
	cout << "\nsize of one element = " << sizeof(yams[0]) << "bytes" << endl;

	return 0;

}
