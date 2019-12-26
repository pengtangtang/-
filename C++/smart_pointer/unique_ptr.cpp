/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：unique_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <memory>
/*unique_ptr不会留下危险的悬挂指针
 * 而auto_ptr会。这就是在容器中禁止使用auto_ptr的原因。*/
unique_ptr<string> demo(const char* s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

int main()
{
	unique_ptr<string> ps;
	ps = demo("unique special");//ps接管原本返回的string对象，而返回的unique_ptr被销毁。
	cout << *ps << endl;
	
	unique_ptr<string> pu1(new string("hi"));
	unique_ptr<string> pu2;
	//pu2 = pu1;//error:会留下悬挂的指针，unique_ptr不允许
	unique_ptr<string> pu3;
	pu3 = unique_ptr<string>(new string("yi"));//调用了unique_ptr的构造函数，该构造函数创建的临时对象在其转让所有权后就会被销毁。
	cout << "*pu1 = " << *pu1 << endl;
	cout << "*pu3 = " << *pu3 << endl;

	unique_ptr<double[]> data (new double[5] {1,2,3,4,5});
	cout << data[0] << endl;
	return 0;
}
