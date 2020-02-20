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

template <typename T>
class Stack{
	public:
		Stack(int size);
		~Stack();

		bool stackEmpty();
		bool stackFull();

		void clearStack();
		int stackLength();

		bool push(T elem);
		bool pop(T& elem);

		void stackTraverse(bool isFromButtom);

	private:

		T* m_pBuffer;//栈空间指针
		int m_iSize;//栈容量
		int m_iTop;//栈顶，栈中元素个数
};
#endif
template <typename T>
Stack<T>::Stack(int size)
{
	m_iSize = size;
	m_iTop = 0;
	m_pBuffer = new T[m_iSize];
}

template <typename T>
Stack<T>::~Stack()
{
	delete []m_pBuffer;
}

template <typename T>
bool Stack<T>::stackEmpty()
{
	return (0 == m_iTop) ? true:false;
}

template <typename T>
bool Stack<T>::stackFull()
{
	return (m_iSize == m_iTop) ? true:false;
}

template <typename T>
void Stack<T>::clearStack()
{
	m_iTop = 0;
}

template <typename T>
int Stack<T>::stackLength()
{
	return m_iTop;
}

template <typename T>
bool Stack<T>::push(T elem)
{
	if(stackFull())
	{
		return false;
	}
	m_pBuffer[m_iTop] = elem;

	m_iTop++;

	return true;
}

template <typename T>
bool Stack<T>::pop(T& elem)
{
	if(stackEmpty())
	{
		return false;
	}
#if 0
	elem = m_pBuffer[m_iTop-1];
	m_iTop--;
#else
	m_iTop--;
	elem = m_pBuffer[m_iTop];
#endif

	return true;
}

template <typename T>
void Stack<T>::stackTraverse(bool isFromButtom)
{
	if(stackEmpty())
	{
		return ;
	}
	if(isFromButtom)
	{
		for(int i = 0; i < m_iTop;i++)
		{
#if 1
			cout << m_pBuffer[i] << " ";
#else
			m_pBuffer[i].printCooordinate();
#endif
		}
	}
	else
	{
		for(int i = m_iTop-1; i >= 0;i--)
		{
#if 1
			cout << m_pBuffer[i] << " ";
#else
			m_pBuffer[i].printCoordinate();
#endif

		}
	}

	cout << endl;
}

