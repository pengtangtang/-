/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "time.h"

int main()
{
	Time planing;
	Time coding(2,12);
	Time fixing(4,6);
	Time total;
	Time total1;
	Time total2;
	Time total3;
#if 0
	total = coding.sum(fixing);
	total.show();
	total1 = total + coding + fixing;
	total1.show();
	total2 = total-total1;
	total3 = total*2.3;
	total2.show();
	total3.show();
	total3 = 2.3*total;
	total3.show();

	cout << total
#else
		/*cout << trip == operator <<(cout ,trip)返回cout */
		cout <<   "coding time: " << coding;
	/*以上语句等价于operator << (cout,"coding") << coding -->opertor(cout,coding),当返回值为cout（so）时可与ostream类的<<一起连用*/
#endif
}
