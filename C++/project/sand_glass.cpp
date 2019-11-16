/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：sand_glass.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月03日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>

int main()
{
	int n;
	char symbol;

	cin >> n >> symbol;

	if(n < 1) return 0;
	n = n-1;

	int max_row = 1;
	int row_num = 0;
	while(n >= 0){
		if(n-2*(max_row+2) < 0) break;
		max_row += 2;
		++row_num;
		n -= max_row*2;
	}
	for(int i=0;i<row_num;i++){
		for(int j=0;i<i;j++){
			cout << " ";
		}
		for(int  j=0;j<max_row-2*i;j++){
			cout << symbol;
		}

		cout << endl;
	}

	for(int i=row_num;i>=0;i--){
		for(int j=0;i<i;j++){
			cout << " ";
		}
		for(int  j=0;j<max_row-2*i;j++){
			cout << symbol;
		}

		cout << endl;
	}
	cout << n;
	return 0;
}
