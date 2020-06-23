/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：EventMechanism.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月22日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <gtest/gtest.h>

/*事件机制*/
class GlobalTest:public testing::Environment
{
	public:
		virtual void SetUp()
		{
			cout << "SetUp\n";
		}
		virtual void TearDown()
		{
			cout << "TearDown\n";
		}
};

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	testing::Environment* env = new GlobalTest();
	testing::AddGlobalTestEnvironment(env);
	return RUN_ALL_TESTS();
}
