/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：re_call.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "array.h"
/*递归使用模板*/
int main()
{
	Array<int,10> sums;
	Array<double,10> aves;
	/*注意：模板中维的顺序与等价的二维数组相反*/
	Array<Array<int,5>,10> twodee;/*twodee一个包含10个元素的数组，其中每个数组都是一个包含5个元素的数组*/

	int i,j;
	for(i=0;i<10;i++)
	{
		sums[i] = 0;
		for(j=0;j<5;j++)
		{
			twodee[i][j] = (i+1)*(j+1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i];
	}

	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}

		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ",aves = " << aves[i] << endl;
	}

	cout << "Done\n";
	return 0;
}
