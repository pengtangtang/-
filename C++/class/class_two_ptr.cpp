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

class example{
public:
	example(int n,int m){
		x = n;
		y = m;
	}
	int get_x(){
		return x;
	}
	int get_y(){
		return y;
	}
private:
	int x,y;
};

int main()
{
	example op[4]={
	example(1,2),example(3,4),example(5,6),example(7,8)
	};

	int i;
	example *p;
	p = &op[3];
	for(i=0;i<4;i++){
		cout << p->get_x() << ' ';
		cout << p->get_y() << '\n';
		p--;
	}

	return 0;
}
