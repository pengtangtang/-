/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Node.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月17日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _NODE_H
#define _NODE_H
#include "Person.h"

class Node{
	public:
		Person data;
		Node* next;

		void printNode();
};
#endif
