/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Stack.h
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _STACK_H
#define _STACK_H

class Stack{
	public:
		Stack(int size);
		~Stack();

		bool stackEmpty();
		bool stackFull();

		void clearStack();
		int stackLength();

		bool push(char elem);
		bool pop(char& elem);

		void stackTraverse(bool isFromButtom);

	private:

		char* m_pBuffer;//栈空间指针
		int m_iSize;//栈容量
		int m_iTop;//栈顶，栈中元素个数
};

#endif
