/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：DeathTest.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <gtest/gtest.h>
int func()
{
	int *ptr = NULL;
	*ptr = 100;
	return 0;
}

TEST(FuncDeathTest,Nullptr)
{
	ASSERT_DEATH(func(),"");
}
int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
