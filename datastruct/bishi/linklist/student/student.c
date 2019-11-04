/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：student.c
*   创 建 者：pengtangtang
*   创建日期：2019年09月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

typedef struct student{
	char name[20];
	int age;
	char sex;
	int no;
	struct student *next;
}mStudent;

mStudent *create_student(int n)
{
	mStudent *head = (mStudent *)malloc(sizeof(mStudent));
	if(NULL == head)
		return NULL;
	head->next = NULL;
	mStudent *p = head;
	mStudent *q;
	int i ;
	printf("input student information:name age sex no\n");
	for(i=0; i<n; i++){
		q = (mStudent *)malloc(sizeof(mStudent));
		q->next = NULL;
		scanf("%s %d %c %d",q->name,&q->age,&q->sex,&q->no);//注意输入格式要与键盘输入保持一致否则容易出现错误
		p->next = q;
		p = q;
	}
	printf("create success\n");
	return head;
}

int delete_student(mStudent *head,int age)
{
	if(NULL == head || age < 0)
		return -1;
	mStudent *p,*q;
	p = head;
	q = p->next;

	while(q){
		if(q->age == age)
			break;
		p = q;
		q = q->next;
	}
	if(!q)
		printf("this student is not in linklist!\n");
	p->next = q->next;
	printf("delete success\n");
	free(q);
	q = NULL;
	return 0;
}

int display_student(mStudent *head)
{
	if(head == NULL)
		return -1;
	mStudent *p = head->next;
	
	printf("name age sex no\n");
	while(p)
	{
		printf("%s %d %c %d\n",p->name,p->age,p->sex,p->no);
		p = p->next;
	}
	return 0 ;
}

int main()
{
	int n;
	printf("input student number:");
	scanf("%d",&n);
	mStudent *head  = create_student(n);
	display_student(head);

	printf("input a student's age which you want to delete:");
	int  age;
	scanf("%d",&age);

	delete_student(head,age);
	display_student(head);

	return 0;
}
