/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月06日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "line.h"

int main()
{
	char num;
	int i,j,a;

	seqlist *sq=seqlist_create();
	printf("\n1:如果输入五个整数，打印出顺序表的内容，并显示表的剩余空间\n2:在顺序表的第3个位置插入元素0，打印顺序的内容，并显示表中的剩余空间\n3:当用户试图插入表中第11个位置时，程序提示超出范围\n4:删除表中第5个元素\n5:退出程序\n");
	while(1)
	{
		scanf("%c",&num);
		if('5' == num)
			break;
		switch(num)
		{
			case '1':
				for(i=0;i<5;i++)
				{
					scanf("%d",&a);
					ini_seqlist(sq,a,i);
				}
				i=print(sq);
				printf("the space reserved %d\n",i);
				break;
			case '2':
				insert_seqlist(sq,0,3);
				i=print(sq);
				printf("i=%d\n",i);
				break;
			case '3':
				insert_seqlist(sq,0,11);
				break;
			case '4':
				del_seqlist(sq,5);
				print(sq);
				break;


		}
	}
	return 0;
}
