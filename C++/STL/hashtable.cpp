/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hashtable.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <hash_set.h>

int main()
{
	hashtable<int,int,hash<int>,identity<int>,equal_to<int>,alloc>iht(50,hash<int>(),equal_to<int>());
	cout << iht.size() << endl;
	return 0;
}
