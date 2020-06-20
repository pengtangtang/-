/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_stream1.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月27日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <fstream>

int main()
{
	fstream ioFile;
	ioFile.open("./test.dat",ios::out);
	ioFile << "qq" << '\t' << 98 << endl;
	ioFile.close();
	ioFile.open("./test.dat",ios::in | ios::binary);

	char name[30];
	int math;
	cout << "name" << '\t' << "math" << endl;
	ioFile >> name;

	while (!ioFile.eof())
	{
		ioFile >> math;
		cout << name << '\t' << math << endl;
		ioFile >> name;
	}

	ioFile.close();
	return 0;
}
