/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
//using namespace std;
#include <iostream>
#include <vector>
#include <array>
#include <string>
int main()
{
	const int Size = 10;

	std::vector<std::string> s1(Size);
	std::array<std::string,Size> s2;

	s1[0] = "pppppppp";
	s1[1] = "dwsdwe";
	s2[0] = "lklk";
	s2[1] = "vovo";
	
	std::string str = "hello";

	s1[2] = str;
	s2[2] = str;

	std::cout << s1[0] << " " << s1[1] << " " << s1[2]  << std::endl;
	std::cout << s2[0] << " " << s2[1] << " " << s2[2]  << std::endl;


	return 0;
}
