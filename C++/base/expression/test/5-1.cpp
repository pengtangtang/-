/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：5-1.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2020年03月16日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstring>

void Sum();
void formore();
void Num0();
void Money();
void Book();
void Car();
void Word();
void User();
void Base();


int main()
{
#if 1
	Base();
#else
	Word();
	User();
	Car();
	book();
	Money();
	Num0();
	formore();
	Sum();
#endif
	return 0;
}

void Base()
{
#if 1
	cout << "please input a int number:";
	int n;
	cin >> n;

	int aa = new int[n];
	vector<int> arr[n];

#else
	float treacle[10] = {1.2,2.2,4.4,};
	float* pp = treacle;

	cout << *pp << " " << pp[9] << endl;

	double ted = 2.22;
	double* pt = &ted;
	cout << *pt << endl;

	enum Response  {Yes = 1,No = 0,May = 2};

	struct fish
	{
		string var;
		int weight;
		float width;
	};

	fish mfish = {"girl",3,2.2};
	{
		array<int,5> a;
		a[0] = 1;

		for(int i = 1;i < 5;i++)
		{
			a[i] = a[i-1]+2;
		}

		int even = a[0] + a[4];
		cout << even << endl;

		for(int i = 0;i < 5;i++)
		{
			cout << a[i] << endl;
		}
	}
	{
		char actor[30];
		short besie[100];
		float chuck[13];
		long double dipsea[64];
		array<char,30> actor_t;
		array<short,100> besie_t;
		array<float,13> chuck_t;
		array<long double,64> dipsea_t;
	}

#endif
}

void User()
{
	int i;
	cout << "please input a int number:";
	cin >> i;

	char pic[i][i];
	for(int j = 0;j < i;j++)
	{
		int m = i-1;
		for(int x = 0;x < i;x++,m--)
		{
			if(m <= j)
			{
				pic[j][x] = '*';
			}
			else
			{
				pic[j][x] = '0';
			}
		}
	}
	for(int j = 0;j < i;j++)
	{
		for(int x = 0;x < i;x++)
		{
			cout << pic[j][x] <<  " ";
		}
		cout << endl;
	}
}

void Word()
{
#if 0
	string str;

	cout << "please input a sentence:";
	getline(cin,str);

	int i,count;
	i = count = 0;
	string temp ;

	for(;str[i] != '\0';i++)
	{
		if(str[i] != ' ')
		{
			temp[i] = str[i];
		}
		else
		{
			if(temp == "done")
			{
				break;
			}
			temp = "\0";
			count++;
		}

	}

	cout << "You entered a total of " << count << " words.\n";


#else
	char word[100];
	int i,count;

	i = count = 0;

	cout << "please input a sentence:";

	char ch;

	while((ch = cin.get()) != '\n')
	{
		word[i] = ch;
		i++;
	}

	char temp[100] = {0};
	for(int j = 0;word[j] != '\0' ;j++)
	{
		if(word[j] != ' ')
		{
			temp[j] = word[j];
		}
		else
		{
			if(!strcmp(temp,"done"))
			{
				break;
			}
			temp[100] = {0};
			count++;
		}

	}
	

	cout << "You entered a total of" << count << " words\n";
#endif
}

struct car
{
	string pro;
	int year;
};

void Car()
{
	cout << "hi owner,how many cars do you wish to catalog?";

	int num;
	cin >> num;

	car* m_car = new car[num];

	for(int i = 0;i < num;i++)
	{
		cout << "Car #" << i+1 << ":\n";
		cout << "Please enter the make:";
		cin >> m_car[i].pro;
		cout << "Please enter the year made:";
		cin >> m_car[i].year;
	}

	cout << "Here is your collection:\n";

	for(int i = 0;i < num;i++)
	{
		cout << m_car[i].year << " " << m_car[i].pro << endl;
	}


}



void Book()
{
	const string Month[] = 
	{
		"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
		"Sep","Oct","Nov","Dec"
	};
#if 1
	const int Size = 12;
	int mem[3][Size];
	int y_sum[3] = {0};

	for (int i = 0;i < 3;i++)
	{
		cout << "input " << i+1 << " year's num!\n";
		for(int  x = 0;x < Size; x++)
		{
			cout << Month[x] << " num = ";
			cin >>  mem[i][x];
			y_sum[i] += mem[i][x];
		}
	
	}

	int a_sum = 0;
	for (int i = 0;i < 3;i++)
	{
		cout << "ouput " << i+1 << " year's num!\n";
		
		cout << y_sum[i] << endl;
		a_sum += y_sum[i];
	}
	
	cout << "all sum = " << a_sum << endl;

#else
	vector<int> num(12);
	int i = 0;
	for(string x : Month)
	{
		cout << x << " num = ";
		cin >>  num[i++];
	}

	int sum = 0;
	for(int j = 0;j < num.size();j++)
	{
		sum += num[j];
	}

	cout << "the sum = " << sum << endl;
#endif
}

void Money()
{
	const int Va = 100;
	const float Da = 0.1;
	const float Cl = 0.05;

	double D,C;
	D = Va*Da + Va;
	C = Va*Cl + Va;
	for(int i = 1;;i++)
	{
		if(D <= C)
		{
			cout << "year = " << i << endl;
			cout << "D = " << D << endl;
			cout << "C = " << C << endl;
			break;
		}
		D += Va*Da;
		C += (C+Va)*Cl;
	}


}

void Num0()
{
	cout << "please input a number:";
	int n,num;
	num = 0;

	cin >> n;
	
	while(n != 0)
	{
		num += n;
		cout << "num = " << num << endl;
		cin >> n;
	}
}

void formore()
{
	const int Size = 101;
	array<long double,Size> factorials;

	factorials[1] = factorials[0] = 1LL;
	for(int i = 2;i < Size;i++)
		factorials[i] = i*factorials[i-1];
	for(int i = 0;i < Size;i++)
		cout << i << " = " << factorials[i] << endl;



}

void Sum()
{
	cout << "please input first int number:";
	int n1;
	cin >> n1;

	cout << "please input second int number:";
	int n2;
	cin >> n2;

	int sum = 0;
	for(int i = n1;i <= n2;i++)
	{
		sum += n1;
	}

	cout << "the sum between n1 and n2 is " << sum << endl;

}
