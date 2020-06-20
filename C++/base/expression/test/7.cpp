/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：7.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2020年03月17日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>
#include <cctype>

float two_num(float x,float y);
void input_func(float score[],int i);
void display_func(float score[],int i);
float average_func(float score[],int i);
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void box_display(box& m);
void box_set(box* m);
int jie_cheng(int i);

int Fill_array(double arr[],int len);
void Show_array(double arr[],int len);
void Reverse_array(double arr[],int len);

int main()
{
#if 1
	double arr[8] = {0};
	int i = Fill_array(arr,8);

	Show_array(arr,i);
	cout << "43\n";
	Reverse_array(arr,i);
	Show_array(arr,i);
#else
	{
		int i ;
		while(1)
		{
			cout << "input a number:";
			cin >> i;
			if(i >= 0)
			{
				cout << jie_cheng(i) << endl;
			}
			else
			{
				cout << "number must big or equal 0\n";
			}
		}
	}
	box b1 = {"tt",1.2,3.2,4.4,0.0};

	box_display(b1);
	box_set(&b1);
	float score[10] = {0};

	input_func(score,10);
	display_func(score,10);

	float average = average_func(score,10);
	cout << "average:" << average << endl;
	cout << "input two number:";
	float x,y;
	cin >> x >> y;

	while(x && y)
	{
		cout << two_num(x,y) << endl;
		cout << "input:";
		cin >> x >> y;
	}
#endif
	return 0;
}

int Fill_array(double arr[],int len)
{
	int i = 0;
	cout << "please input arr emel:";

	cin >> arr[i];
	while(i < len && isdigit(arr[i]))
	{
		i++;
		cout << i << endl;
		cin >> arr[i];
		cout << arr[i];
	}
	return i;
}

void Show_array(double arr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Reverse_array(double arr[],int len)
{
	double temp = 0;
	int i = 1;
	int j = len-2;
	for(;i < j;i++,j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int jie_cheng(int i)
{
	int m = 0;
	if(0 == i || 1 == i)
	{
		m = 1;
	}
	else
	{
		m = i*jie_cheng(i-1);
	}
	return m;
}

void box_set(box* m)
{
	m->volume = m->height*m->length*m->width;
	cout << "volume = " << m->volume << endl;
}

void box_display(box& m)
{
	cout << "maker:" << m.maker << endl
		<< "height:" << m.height << endl
		<< "width:" << m.width << endl
		<< "length:" << m.length << endl
		<< "volume:" << m.volume << endl;
}

void input_func(float score[],int i)
{
	cout << "please input score,-1 is end input: ";
	int j = 0;

	while(j < i)
	{
		cin >> score[j];
		if(-1 == score[j])
		{
			score[j] = 0;
			break;
		}
		j++;
	}
}
void display_func(float score[],int i)
{
	for(int j = 0;j < i && score[j] != 0;j++)
	{
		cout << score[j] << " ";
	}
	cout << endl;
}

float average_func(float score[],int i)
{
	float sum = 0;

	int j = 0;

	for(;j < i && score[j] != 0;j++)
	{
		sum += score[j];
	}

	cout << sum << endl;
	return sum/j;
}

float two_num(float x,float y)
{
	return 2.0*x*y/(x+y);
}
