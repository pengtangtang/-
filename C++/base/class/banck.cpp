/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：banck.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年03月31日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "queue.h"
#include <ctime>
#include <cstdlib>

const int MIN_PER_HR = 60;

bool newcustomer(double x);//模拟客户到来
/*ATM模拟：允许用户输入3个数：队列最大长度、程序模拟持续时间（小时为单位）、平均每小时客户数。程序使用循环--每次循环代表一分钟*/
int main()
{
	srand(time(0));//random initializing of rand()

	cout << "Case Study:Bank og heather automic teiler\n";
	cout << "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs);//line queue holds up to qs people

	cout <<"Enter the number of simulation hours:";
	int hours;
	cin >> hours;
	long cyclelimit  = MIN_PER_HR*hours;

	cout << "ENter the average number of customers per hour:";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR/perhour;

	Item temp;
	long turnaways = 0;//turn away by ful queue
	long customers = 0;//joined the queue
	long served = 0;//served during the simultion
	long sum_line = 0;//cumulative line length
	long wait_time = 0;//time until autoteller is free
	long line_wait = 0;//cumulative time in line

	for(int cycle = 0;cycle < cyclelimit;cycle++)
	{
		if (newcustomer(min_per_cust))//判断是否有新客户，有就入队
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//设置客户细信息
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{//若没有客户交易，将第一个出队。确定客户等待时间并将wait_time计数器设置为新客户所需处理时间。
			line.dequeue (temp);//attend next customer
			wait_time = temp.ptime();//一个需要的时间
			line_wait += cycle - temp.when();
			served++;
		}
		if(wait_time > 0)
		{
			wait_time--;
		}
		sum_line += line.queuecount();
	}

	if(customers > 0)
	{
		cout << "customers accepted:" << customers << endl;
		cout << " customers served:" << served << endl;
		cout << " average queue size:";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time:";
		cout << (double) line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand()*x/RAND_MAX < 1);
}
