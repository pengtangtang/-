/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：vector.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月22日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <deque>
#if 0
int main()
{
	vector<int> vec;
	int i;

	cout << "vector size = " << vec.size() << endl;

	for(i=0; i<5; i++){
		vec.push_back(i);
	}
	cout << "vector size = " << vec.size() << endl;

	for(i=0; i<5; i++){
		cout << "value of vec[" << i << "] = " << vec[i] << end;
	}

	vector<int>::iterator v = vec.begin();
	while(v != vec.end()){
	cout << "value of v = " << *v << endl;
	v++;
	}
	return 0;

}
#else
template <typename T>
ostream& operator << (ostream& os,const deque<T>& obj)
{
	os << "[";
	for(int i = 0;i < obj.size();i++)
		os << obj[i] << " ";
	os << "]";
}

int main()
{
	deque<int> d = {1,2,3,4};
	cout << "size：" << d.size() << endl;
	cout << d << endl;

	d.push_front(10);
	cout << d << endl;

	d.pop_front();
	cout << d << endl;

	d.resize(3);
	cout << d << endl;
	return 0;
}
#endif
