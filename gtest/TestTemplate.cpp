/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：TestTemplate.cpp
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

namespace {
//测试固件
class FooTest:public testing::Test{
	public:
		Footest(){}
		virtual ~FooTest(){}

		//当构造析构函数不能满足初始化和清除工作，可以使用下面两个函数代替
		virtual void SetUp(){}
		virtual void TearDown(){}
};

//test
TEST_F(FooTest,MethodBarDoesAbc)
{
	const string input_filepath = "this/package/testdata/input";
	const string output_filepath = "this/package/testdata/output";
	Foo f;
	EXPECT_EQ(0,F.Bar(input_filepath,output_filepath));
}
}

int main(int argc,char* argv[]){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
