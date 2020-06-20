/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：String.cpp
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
#include <cstdlib>
#include <cctype>

class String
{
	private:
		char* str;
		int len;
		static int num_strings;
		static const int CINLIM = 80;
	public:
		String(const char* s);
		String();
		String(const String&);
		~String();
		int length() const { return len; }

		String& operator = (const String&);
		String& operator = (const char*);
		char& operator [] (int i);
		const char& operator [] (int i) const;

		bool Stringlow();
		bool Stringup();
		int Charcount(char a);

		friend bool operator < (const String& st,const String& st2);
		friend bool operator > (const String& st,const String& st2);
		friend String operator + (const char* st,const String& st2);
		friend String operator + (const String& st,const String& st2);
		friend bool operator == (const String& st,const String& st2);
		friend ostream& operator << (ostream& os,const String& st);
		friend istream& operator >> (istream& is,String & st);

		static int HowMany();
};

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

bool String::Stringlow()
{
	for(int i = 0;i < len;i++)
	{
		if(isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
	return true;
}

bool String::Stringup()
{
	for(int i = 0;i < len;i++)
	{
		if(islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
	}
	return true;
}

int String::Charcount(char a)
{
	int count = 0;
	for(int i = 0;i < len ;i++)
	{
		if(str[i] == a)
			count++;
	}

	return count;
}
String operator + (const char* st,const String& st2)
{
	String s;
	s.len = strlen(st) + st2.len;
	s.str = new char[s.len+1];
	strcpy(s.str,st);
	strcat(s.str,st2.str);
	return s;
}

String operator + (const String& st,const String& st2)
{
	String s;
	s.len = st.len + st2.len;
	s.str = new char[s.len+1];
	strcpy(s.str,st.str);
	strcat(s.str,st2.str);
	return s;
	
}
String::String(const char* s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	len = st.len;
	str = new char[len+1];
	strcpy(str,st.str);

	num_strings++;
}

String::~String()
{
	--num_strings;
	delete [] str;
}

String& String::operator = (const String& st)
{
	if(&st == this)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len+1];
	strcpy(str,st.str);
	return *this;
}

String& String::operator = (const char* s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
	return *this;
}

char& String::operator [] (int i)
{
	return str[i];
}

const char& String::operator [] (int i) const
{
	return str[i];
}

bool operator < (const String& st,const String& st2)
{
	return (strcmp(st.str,st2.str) < 0);
}

bool operator > (const String& st,const String& st2)
{
	return (strcmp(st.str,st2.str) > 0);
}

bool operator == (const String& st,const String& st2)
{
	return (strcmp(st.str,st2.str) == 0);
}

ostream& operator << (ostream& os,const String& st)
{
	os << st.str;
	return os;
}

istream& operator >> (istream& is,String & st)
{
	char temp[String::CINLIM];
	is.get(temp,String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}
