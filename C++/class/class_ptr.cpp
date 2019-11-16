/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
/*指针只能访问对象的公有成员*/

class exe{
	public: 
		void set_a(int a){x = a;}
		void show_a(){cout << x << endl;}
	private:
		int x;
};

int main()
{
#if 0
	exe ob,*p;
	ob.set_a(1);
	ob.show_a();
	p=&ob;
	p->show_a();
#else
	exe ob[2],*p;
	ob[0].set_a(9);
	ob[1].set_a(10);
	p = ob;
	p++;
	p->show_a();
#endif
	return 0;
}
