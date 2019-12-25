/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：use_asles.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "sales.h"

int main()
{
	double vals1[12] =
	{
		1220,1100,1122,2212,1232,2334,
		1884,2393,3302,2922,3002,3544
	};

	double vals2[12] =
	{
		12,11,22,21,32,34,
		28,29,33,29,32,35
	};

	//实例化
	Sales sales1(2011,vals1,12);
	LabeledSales sales2("Blogstar",2012,vals2,12);

	Sales::bad_index* S;
	LabeledSales::nbad_index* L;

	cout << "first try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for(i = 0;i < 12;++i)
		{
			cout << sales1[i] << ' ';
			if(i%6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;

		for(i = 0;i < 12; ++i)
		{
			cout << sales2[i] << ' ';
			if(i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}//首先写子类的catch再写基类的catch：因为基类的引用可以对任意的异常作出反应，没有类异常处理的选择
	catch(logic_error& bad)
	{
		cout << bad.what();
		if(L = dynamic_cast<LabeledSales::nbad_index *>(&bad))
		{
		cout << "Company: " << L->label_val() << endl;
		cout << "bad index:" << L->bi_val() << endl;
		}
		else if(S = dynamic_cast<Sales::bad_index*>(&bad))
		{
			cout << "bad index: " << S->bi_val() << endl;
		}
	}
	cout << "Next try block:\n";
	try{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch(logic_error& bad)
	{
		cout << bad.what();
		if(L = dynamic_cast<LabeledSales::nbad_index *>(&bad))
		{
			cout << "Company: " << L->label_val() << endl;
			cout << "bad index: " << L->bi_val() << endl;
		}
		else if(S = dynamic_cast<Sales::bad_index*>(&bad))
		{
			cout << "bad index: " << S->bi_val() << endl;
		}

	}
	cout << "done\n";
	return 0;
}
