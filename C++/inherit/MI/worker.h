/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：work.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _WORK_H
#define _WORK_H

#include <string>

class Worker{

public:
	Worker():fullname("no one"),id(0) {}
	Worker(const string& s,long n):fullname(s),id(n) {}
	virtual ~Worker() = 0;
	virtual void set();
	virtual void show() const;
private:
	string fullname;
	long id;

};

class Waiter:virtual public Worker{

public:
	Waiter():Worker(),panache(0) {}
	Waiter(const string& s,long n,int p = 0):Worker(s,n),panache(p) {}
	Waiter(const Worker& wk,int p = 0):Worker(wk),panache(p) {}

	void set();
	void show() const;
private:
	int panache;
};


class Singer:virtual public Worker{

public:
	Singer():Worker(),voice(other) {}
	Singer(const string& s,long n,int v = other):Worker(s,n),voice(v) {}
	Singer(const Worker& wk,int v = other):Worker(wk),voice(v) {}

	void set();
	void show() const;
protected:
	enum {other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes = 7};
private:
	static char* pv[Vtypes];
	int voice;
};

class SingerWaiter:public Singer,public Waiter{
	public:
		void set() {}
		void show() const{}
};
#endif
