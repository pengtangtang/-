/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：12.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月01日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstring>
#include "String.h"

class Cow{
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm,const char* ho,double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator = (const Cow& c);
	void ShowCow() const;
};

Cow::Cow()
{
	strcpy(name,"pp");
	hobby = new char[1];//先分配空间再赋值
	hobby[0] = '\0';
	weight = 0.0;
}
Cow::Cow(const char* nm,const char* ho,double wt)
{
	strncpy(name,nm,20);
	hobby = new char[strlen(ho)+1];
	strcpy(hobby,ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy(name,c.name);
	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}
Cow& Cow::operator = (const Cow& c)
{
	if(this == &c)
		return *this;

	strcpy(name,c.name);

	delete [] hobby;
	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight = c.weight;
	return *this;	
}
void Cow::ShowCow() const
{
	cout << "name:" << name << endl
		<< "hobby:" << hobby << endl
		<< "weight:" << weight << endl;
}


typedef unsigned long Item;

class Stack
{
	private:
		enum {MAX = 10};
		Item* pitems;
		int size;
		int top;
	public:
		Stack(int n = MAX);
		Stack(const Stack& st);
		~Stack();

		bool isempty() const;
		bool isfull() const;
		bool push(const Item& item);
		bool pop(Item& item);
		Stack& operator = (const Stack& st);

		void Show()
		{
			for(int i = 0;i < top;i++)
			{
				cout << pitems[i] << " ";
			}
			cout << endl;
		}
};

Stack::Stack(int n)
{
	top = 0;
	size = n;
	pitems = new Item[size];
}

Stack::Stack(const Stack& st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for(int i = 0;i < top;i++)
	{
		pitems[i] = st.pitems[i];
	}

}
Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return (0 == top);
}
bool Stack::isfull() const
{
	return (size == top);
}

bool Stack::push(const Item& item)
{
	if(isfull())
		return false;
	pitems[top] = item;
	top++;
	return true;
}
bool Stack::pop(Item& item)
{
	if(isempty())
		return false;
	item = pitems[--top];
	return true;
}
Stack& Stack::operator = (const Stack& st)
{
	size = st.size;
	top = st.top;
	delete [] pitems;
	pitems = new Item[size];
	for(int i = 0;i < top;i++)
	{
		pitems[i] = st.pitems[i];
	}
	return *this;
}


int main()
{
#if 1
	Stack s;
	Stack s1(s);

	Item it = 1;
	s.push(it);
	s.Show();
	s.pop(it);
	s.Show();

	s = s1;
	s.Show();
#else
	String s1("and I an a C++ student.");
	String s2 = "Please enter your name:";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";

	s2 = s2 + s1;
	s2.Stringup();
	cout << endl;

	cout << " the string \n" << s2 << "\ncontains " << s2.Charcount('A')
		<< " 'A' characters in it\n";
	s1 = "red";
	String rgb[3] = {String(s1),String("green"),String("blue")};
	cout << "Enter the name of a primary color for mixing light:";
	String ans;
	bool success = false;

	while(cin >> ans)
	{
		ans.Stringlow();
		for(int i = 0;i < 3;i++)
		{
			if(ans == rgb[i])
			{
				cout << "That's right！\n";
				success = true;
				break;
			}
		}
		if(success)
		{
			break;
		}
		else
			cout << "Try again!\n";
	}

	cout << "Bye\n";
	Cow c1;
	Cow c2("hh","op",3.2);
	Cow c3(c2);
	Cow c4 = c1;
	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	c4.ShowCow();
#endif
	return 0;
}
