/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：rtti1.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

class Grand{
	public:
		Grand(int h = 0):hold(h) {}
		virtual void Speak() const
		{ cout << "I am a grand class\n";}

		virtual int Value() const
		{ return hold; }
	private:
		int hold;
};

class Superb : public Grand{
	public:
		Superb(int h = 0):Grand(h) {}
		void Speak() const
		{ cout << "I am a superb class\n"; }
		virtual void Say() const
		{ cout << "I hold the super value of " << Value() << "\n";  }
};

class Magnificent : public Superb{
	public:
		Magnificent(int h = 0,char c = 'A'):Superb(h),ch(c) {}
		void Speak() const
		{ cout << "I am a Magnificient class\n"; }
		void Say() const
		{ cout << "I hold the character " << ch << " and the integer " << Value() << endl; }
	private:
		char ch;
};

Grand* Getone();

int main()
{
	srand(time(0));
	Grand* pg;
	Superb* ps;
	for(int i = 0;i < 5;i++)
	{
		pg = Getone();
		pg->Speak();
		if(ps = dynamic_cast<Superb *>(pg))
				ps->Say();
	}
	return 0;
}

Grand* Getone()
{
	Grand* p;
	switch(rand()%3)
	{
		case 0:
			p = new Grand(rand()%100);
			break;
		case 1:
			p = new Superb(rand()%100);
			break;
		case 2:
			p = new Magnificent(rand()%100,'A'+rand()%26);
			break;
	}
	return p;
}
