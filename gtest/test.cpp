/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月22日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <gtest/gtest.h>//注意斜杠方向，左斜杠有可能找不到头文件
int Foo(int a,int b)
{
	   if(0 == a||0 == b)
		      throw "don't do that";
	      int c = a%b;
	         if (0 == c)
			   {
				        return b;
					  }
		   return Foo(b,c);
}
// TEST宏的作用是创建一个简单测试，它定义了一个测试函数，在这个函数里可以使用任何C++代码并使用提供的断言来进行检查。
TEST(FooTest,HandleNoneZeroInput)//名称随便
{
	   EXPECT_EQ(2,Foo(4,10));
	      EXPECT_EQ(6,Foo(30,18));
}
int main(int argc,char*argv[])
{
	//将命令行参数传递给gtest
	   testing::InitGoogleTest(&argc,argv);
	   //运行所有测试案例
	      return RUN_ALL_TESTS();
}
