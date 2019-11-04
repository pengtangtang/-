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
int search(int *a,int n,int k);

int main()
{
	int a[10]={12,34,54,2,43,54,6,78,98,10};
	char b;
	int k;
	while(1)
	{
		printf("input your key:\n");
		scanf("%d",&k);
		getchar();
		if(-1==search(a,N,k))
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

int search(int *a,int n,int k)//从后往前查,返回-1则没找到
{

	int i=n-1;
	for(;i>=0;i--)
	{
		if(k == a[i])
			return i;
	}
	return i;
}
