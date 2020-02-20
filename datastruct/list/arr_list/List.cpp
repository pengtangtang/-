/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：List.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月15日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "List.h"

List::List(int size)
{
	m_iSize = size;
	m_pList = new Coordinate[m_iSize];
	m_iLength = 0;
}

List::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	m_iLength = 0;
}

bool List::ListEmpty()
{
	return (m_iLength!=0) ? false:true;
}

int List::ListLength()
{
	return m_iLength;
}

bool List::GetElem(int i,Coordinate* e)
{
	if(i < 0 || i >= m_iSize)
	{
		return false;
	}
	if(NULL == e)
	{
		return false;
	}

	*e = m_pList[i];

	return true;
}

int List::LocateElem(Coordinate* e)
{
	for(int i = 0;i < m_iLength;i++)
	{
		if(*e == m_pList[i])
		{
			return i;
		}
	}

	return -1;
}

bool List::PriorElem(Coordinate* currentElem,Coordinate* preElem)
{
#if 0
	for(int i = 0;i < m_iLength;i++)
	{
		if(i==0 && m_pList[i]==*currentElem)
		{
			return false;
		}

		if(m_pList[i] == *currentElem)
		{
			*preElem = m_pList[i-1];
			return true;
		}
	}
#else
	int temp = LocateElem(currentElem);
	if(-1 == temp)
	{
		return false;
	}
	else
	{
		if(0 == temp)
		{
			return false;
		}
		else
		{
			*preElem = m_pList[temp-1];
			return true;
		}
	}
#endif

	return false;
}

bool List::NextElem(Coordinate* currentElem,Coordinate* nextElem)
{
	int temp = LocateElem(currentElem);
	if(-1 == temp)
	{
		return false;
	}
	else
	{
		if(m_iLength-1 == temp)
		{
			return false;
		}
		else
		{
			*nextElem = m_pList[temp+1];
			return true;
		}
	}

	return false;
}

void List::ListTraverse()
{
	for(int i = 0;i < m_iLength;i++)
	{
		cout << m_pList[i] << " ";
		//m_pListp[i].prinCoordinate();
	}
	cout << endl;
}

bool List::ListInsert(int i,Coordinate* e)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}

	for(int k = m_iLength-1;k >= i;k--)
	{
		m_pList[k+1] = m_pList[k];
	}
	m_pList[i] = *e;
	m_iLength++;

	return true;
}

bool List::ListDelete(int i,Coordinate* e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}

	*e = m_pList[i];
	for(int k = i+1;k < m_iLength;k++)
	{
		m_pList[k-1] = m_pList[k];
	}
	m_iLength--;
	return true;
}
