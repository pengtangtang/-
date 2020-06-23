/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Test_F.cpp
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
#include <map>

class TestMap:public testing::Test
{
	public:
		//添加日志
		static void SetUpTestCase()
		{
			cout << "SetUpTestCase\n";
		}
		static void TearDownTestCase()
		{
			cout << "TestDownTestCase\n";
		}
		virtual void SetUp()//TEST炮制前会执行SetUp
		{
			cout << "SetUp\n";
			test_map.insert(make_pair(1,2));
			test_map.insert(make_pair(0,1));
			test_map.insert(make_pair(3,2));
			test_map.insert(make_pair(4,3));
		}
		virtual void TearDown()//TEST跑完之后会执行TearDown
		{
			cout << "TearDown\n";
			test_map.clear();
		}

		map<int,int> test_map;
};

//TEST_F第一个参数必须与类名一致
TEST_F(TestMap,Find)
{
	map<int,int>::iterator it = test_map.find(1);
	ASSERT_NE(it,test_map.end());
}
TEST_F(TestMap,Size)
{
	ASSERT_EQ(test_map.size(),5);
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
