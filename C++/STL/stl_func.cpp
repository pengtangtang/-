/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：stl_func.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct review{
	string title;
	int rating;
};

bool operator < (const review& r1,const review& r2);
bool worse_than(const review& r1,const review& r2);
bool fill_review(review& rr);
void show_review(const review& rr);

int main()
{
	vector<review> books;
	review temp;
	while(fill_review(temp))
		books.push_back(temp);

	if(books.size() > 0)
	{
		cout << "thank you.you entered the following " << books.size() << " rating:\n"
			<< "rating\tbooks\n";
		for_each(books.begin(),books.end(),show_review);

		sort(books.begin(),books.end());

		cout << "sorted by title:\nrating\tbook\n";

		for_each(books.begin(),books.end(),show_review);
		sort(books.begin(),books.end(),worse_than);
		cout << "sorted by rating:\nrating\tbook\n";
		for_each(books.begin(),books.end(),show_review);

		random_shuffle(books.begin(),books.end());
		cout << "after shuffling:\nrating\tbook\n";
		for_each(books.begin(),books.end(),show_review);

	}
	else 
		cout << "no entry\n";
	return 0;
}

bool operator < (const review& r1,const review& r2)
{
	if(r1.title < r2.title)
		return true;
	else if(r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool worse_than(const review& r1,const review& r2)
{
	if(r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool fill_review(review& rr)
{
	cout << "enter book title(q to quit):";
	getline(cin,rr.title);
	if(rr.title == "quit")
		return false;
	cout << "enter book rating:";
	cin >> rr.rating;

	if(!cin)
		return false;

	while(cin.get() != '\n')
		continue;
	return true;
}
void show_review(const review& rr)
{
	cout << rr.title << "\t" << rr.rating << endl;
}
