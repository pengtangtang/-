/*===============================================================
 *   Copyright (C) 2019 All rights reserved.
 *   
 *   文件名称：my_convert.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2019年12月24日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>

#if 0
class Integer{
	public:
		Integer(int num = 0) { val = num; }
		int getVal() { return val; }

		operator int () const;
	private:
		int val;
};

Integer::operator int () const {
	return val;
}
int main()
{

	Integer obj(100);
	cout << obj.getVal() << endl;

	int num = obj;
	cout << "num = " << num << endl;
	return 0;
}
#else
class Stonewt{

	private:
		enum {Lbs_per_stn = 14};
	public:
		Stonewt(double lbs);//构造函数只允许从某种类型到类类型的转换，相反的转换需要自定义转换函数
		Stonewt(int stn,double lbs);
		Stonewt();
		~Stonewt();
		void show_lbs() const;
		void show_stn() const;
		//operator int() const;
		//operator double() const;
		int Stone_to_int() { return int(pounds+0.5); }
		double Stone_to_double() { return double(pounds); }

	private:
		int stone;
		double pds_left;
		double pounds;

};

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs)/Lbs_per_stn;
	pds_left = int(lbs)%Lbs_per_stn+lbs-int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn,double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn+Lbs_per_stn+lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{

}

void Stonewt::show_lbs() const
{

	cout << pounds << " pounds\n";
}
void Stonewt::show_stn() const
{
	cout << stone << " stone," << pds_left << " pounds\n";
}


/*Stonewt::operator int() const
{
	return int(pounds+0.5);
}
Stonewt::operator double() const
{
	return pounds;
}
*/
int main()
{
	Stonewt pop(9,6.6);

	cout << "convert to double =>\n";
	cout << "pop:" << pop.Stone_to_double() << " pounds\n";
	cout << "convert to int =>\n";
	cout << "pop:" << pop.Stone_to_int() << " pounds\n";
	return 0;
}
#endif
