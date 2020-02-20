/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：Stack.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2020年02月15日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>
#include "Stack.h"

Stack::Stack(int size)
{
	m_iSize = size;
	m_iTop = 0;
	m_pBuffer = new char[m_iSize];
}

Stack::~Stack()
{
	delete []m_pBuffer;
}

bool Stack::stackEmpty()
{
	return (0 == m_iTop) ? true:false;
}

bool Stack::stackFull()
{
	return (m_iSize == m_iTop) ? true:false;
}

void Stack::clearStack()
{
	m_iTop = 0;
}

int Stack::stackLength()
{
	return m_iTop;
}

bool Stack::push(char elem)
{
	if(stackFull())
	{
		return false;
	}
	m_pBuffer[m_iTop] = elem;

	m_iTop++;

	return true;
}

bool Stack::pop(char& elem)
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

void Stack::stackTraverse(bool isFromButtom)
{
	if(stackEmpty())
	{
		return ;
	}
	if(isFromButtom)
	{
		for(int i = 0; i < m_iTop;i++)
		{
			cout << m_pBuffer[i] << " ";
		}
	}
	else
	{
		for(int i = m_iTop-1; i >= 0;i--)
		{
			cout << m_pBuffer[i] << " ";
		}
	}

	cout << endl;
}
