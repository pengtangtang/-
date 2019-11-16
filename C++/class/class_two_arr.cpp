/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：class_arr.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#if 1

class example{
	public:
		example(int n,int m){
			x = n;
			y = m;
		}
		~example(){
			cout << "Destruct called.\n";
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
	example op[3][2]={
	example(1,2),example(3,4),example(5,6),example(7,8),example(9,10),example(11,12)
	};

	int i;
	for(i=0;i<3;i++){
		cout << op[i][0].get_x() << ' ';
		cout << op[i][0].get_y() << '\n';
		cout << op[i][1].get_x() << ' ';
		cout << op[i][1].get_y() << '\n';
	}
	return 0;
}

#else
class exam{
	public:
		exam(){x = 123;}
		exam(int n){x = n;}
		int get_x(){return x;}
	private:
		int x;
};

int main()
{
	exam ob1[4]={11,22,33,44};
	exam ob2[4]={55,66};
	exam ob3[4]={exam(11),exam(22),exam(33),exam(44)};
	exam ob4[4]={exam(55),exam(66)};
	ob4[2]=exam(77);
	ob4[3]=exam(88);

	int i;
	for(i=0;i<4;i++)
		cout << ob1[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob2[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob3[i].get_x() << ' ';
	cout << endl;
	for(i=0;i<4;i++)
		cout << ob4[i].get_x() << ' ';
	cout << endl;
	return 0;
}

#endif
