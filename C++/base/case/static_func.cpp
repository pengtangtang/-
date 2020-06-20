/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：static_func.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

class Application
{
	public:
		static void f();
		static void g();
	public:
		static int global;
};

int Application::global = 0;
void Application::f()
{
	global = 5;
}

void Application::g()
{
	cout << global << endl;
}

int main()
{
	Application::f();
	Application::g();
	return 0;
}
