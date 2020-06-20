/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_stream2.cpp
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
	char ch;
	ofstream out("./t.dat",ios::out | ios::binary);
	for (int i = 0;i < 90;i++)
	{
		if (i > 0 && (i%30)==0)
			out.put('\t');
		out.put(i);
		out.put(' ');
	}
	out.close();

	ifstream in("./t.dat",ios::in | ios::binary);
	while (in.get(ch))
	{
		cout << ch;
	}
	in.close();
	return 0;
}
