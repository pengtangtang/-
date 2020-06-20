/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：permutation.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年04月26日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <algorithm>
#if 1

public class hello {

	public static int arr[] = new int[] {1,2,3};
	public static void main(String[] arg) {
		perm(arr,0,arr.length-1);
	}
	private static void swap(int i1,int i2) {
		int temp = arr[i2];
		arr[i2] = arr[i1];
		arr[i1] = temp;
	}

	public static void perm(int arr[],int begin,int end)
	{
		if (end == begin)
		{
			for (int i = 0;i <= end;i++)
			{
				System.out.println();
				return ;
			}
		}
		else{
			for (int j = begin;j <= end;j++)
			{
				swap(begin,j);
				perm(arr,begin+1,end);
				swap(begin,j);
			}
		}
	}
};

#else
int main()
{
	int arr[] = {3,2,1};
	cout << "pre_permutation\n";

	do
	{
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
	}while(prev_permutation(arr,arr+3));

	int arr1[] = {1,2,3};
	cout << "next_permutation\n";

	do
	{
		cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << endl;
	}while(next_permutation(arr1,arr1+3));

		return 0;
}
#endif
