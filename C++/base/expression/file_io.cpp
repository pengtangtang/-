/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_io.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;

int main()
{
	char filename[SIZE];
	ifstream inFile;

	cout << "Enter name of data file:";

	cin.getline(filename,SIZE);

	inFile.open(filename);

	if(!inFile.is_open())
	{
		cout << "COuld not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while(inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}

	if (inFile.eof())
	{
		cout << "End of file reached.\n";
	}
	else if(inFile.fail())
	{
		cout << "Input terminated by data mismatch.\n";
	}
	else
	{
		cout << "Input teminated for unknown reason.\n";
	}

	if (0 == count)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read:" << count << endl;
		cout << "Sum:" << sum << endl;
		cout << "Average:" << sum/count << endl;
	}

	inFile.close();
	
	return 0;
}
