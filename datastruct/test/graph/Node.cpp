/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Node.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年02月10日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "Node.h"

Node::Node(char data)
{
	m_cData = data;
	m_bIsVisited = false;
}
