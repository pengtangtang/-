/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：enrich_vect.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年12月25日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include <string>

struct review{
	string title;
	int rating;
};

bool fill_review(review& rr);
void show_review(review& rr);

int main()
{
	vector<review> books;
	review temp;
	while(fill_review(temp))
		books.push_back(temp);

	int num = books.size();
	if(num > 0)
	{
		cout << "Thank you ,you entered the following:\n"
			<<"rating\tbook\n";
		for(int i = 0;i < num;i++)
			show_review(books[i]);
		cout << "reprising:\n"
			<< "rating\tbook\n";
		vector<review>::iterator pr;
		for(pr = books.begin();pr != books.end();pr++)
			show_review(*pr);

		vector<review> oldlist(books);

		if(num > 3)
		{
			books.erase(books.begin()+1,books.begin()+3);
			cout << "after erase:\n";
			for(pr = books.begin();pr != books.end();pr++)
				show_review(*pr);

			books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
			cout << "after inster:\n";
			for(pr = books.begin();pr != books.end();pr++)
				show_review(*pr);


			
		}
		else
		{
			cout << "nothing entered\n";
		}
	}
	return 0;
}

bool fill_review(review& rr)
{
	cout << "enter book title(q to quit):";
	getline(cin,rr.title);
	if(rr.title == "quit")
		return false;
	cout << "enter vook rating: ";
	cin >> rr.rating;
	
	if(!cin)
		return false;
	//get rid of rest of input line
	while(cin.get() != '\n')
		continue;
	return true;
}

void show_review(review& rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}
