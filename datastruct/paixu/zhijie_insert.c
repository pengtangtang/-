/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：zhijie_insert.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月10日
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
int insertsort(int *a);

int main()
{
	int a[N]={12,4,3,5,7,2,43,5,65,43};
	insertsort(a);
	int i;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
int insertsort(int *a)
{
	int i;
	for(i=1;i<N;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
