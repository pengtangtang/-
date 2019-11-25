/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：memb_temp.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

template<typename T>
class beta{
	public:
		beta(T t,int i):q(t),n(i){}
		template<typename U>
		U blab(U u,T t) {return (n.Value()+q.Value())*u/t; }
		void show() const {q.show(); n.show();}
	private:
		template<typename V>
			class hold{
				public:
					hold(V v=0):val(v){}
					void show()const{cout << val << endl;}
					V Value()const{return val;}
				private:
					V val;
			};
		hold<T> q;
		hold<int> n;
};

int main()
{
	beta<double> guy(3.5,3);
	cout << "T was set to double\n";

	guy.show();

	cout << "V was set to T,which is double,then V was set to int\n";
	cout << guy.blab(10,2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0,2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done\n";

	return 0;
}
