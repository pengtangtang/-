/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：shunxu.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#define N 10
int halfsearch(int *a,int n,int k);

int main()
{
	int a[10]={12,13,14,34,45,67,76,89,98,99};
	char b;
	int k;
	while(1)
	{
		printf("input your key:\n");
		scanf("%d",&k);
		getchar();
		if(-1==halfsearch(a,N,k))
		{
			printf("no\n");
		}
		else
			printf("yes\n");
		printf("countiue:y over :n   :");
		b=getchar();
		if(b=='n')
			break;
	}
}

int halfsearch(int *a,int n,int k)//从后往前查,返回-1则没找到
{

	int low=0;
	int high=n-1;
	int mid=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])
			return mid;
		if(a[mid]>k)
			high=mid-1;
		if(a[mid]<k)
			low=mid+1;
	}
	return -1;
}
