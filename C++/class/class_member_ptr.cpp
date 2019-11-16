/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_member_ptr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
/*指向成员的指针只能访问公有数据成员与公有成员函数
 * 使用要先声明在赋值最后访问*/

#if 0
class A{
	public:
		A(int i){z = i;}
		int z;
};

int main()
{
	A ob(5);
	A *pc1;
	pc1 = &ob;

	int A::*pc2;
	pc2 = &A::z;

	cout << ob.*pc2 << endl;
	cout << pc1->*pc2 << endl;
	cout << ob.z << endl;
	return 0;
}
#else

class Coord{
	public:
		Coord(int a=0,int b=0) { 
			x = a;
			y = b;
		}
		int get_x() {
			return x;
		}
		int get_y() {
			return y;
		}
	private:
		int x,y;
};

int main()
{
	Coord op(5,6);
	Coord *pc1 = &op;

	int (Coord::*pc_getx)();
	pc_getx = &Coord::get_x;


	cout << pc1->get_x() << endl;
	cout << (pc1->*pc_getx)() << endl;
	cout << (op.*pc_getx)() << endl;
	return 0;
}
#endif
