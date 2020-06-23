/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：Gtest.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2020年06月23日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
#include<iostream>
using namespace std;
#include<gtest/gtest.h>

struct LinkNode
{
	int _data;
	LinkNode *_next;
	LinkNode(const int& data)
		:_data(data)
		 ,_next(NULL)
	{}
};

class Link
{
	public:
		Link()
			:pHead(new LinkNode(0))
		{}
		void PushBack(const int& data)
		{
			if(pHead == NULL)
				return ;
			LinkNode *newNode=new LinkNode(data);
			if(pHead->_next == NULL){  //第一次插入结点
				pHead->_next=newNode;
			}
			else{  //找到最后一个结点直接尾插
				LinkNode *cur=pHead->_next;
				while(cur->_next){
					cur=cur->_next;
				}
				cur->_next=newNode;
			}
		}

		void PopBack()
		{
			if(pHead == NULL)
				return ;
			LinkNode *cur=pHead;
			LinkNode *prev=NULL;
			while(cur->_next)
			{
				prev=cur;
				cur=cur->_next;
			}
			prev->_next=NULL;
			delete cur;
		}

		LinkNode *FindNode(const int& data)
		{
			if(pHead == NULL)
				return NULL;
			LinkNode *cur=pHead->_next;
			while(cur)
			{
				if(cur->_data == data)
					return cur;
				cur=cur->_next;
			}
			return NULL;
		}

		bool Delete(int data)
		{
			LinkNode *pos=FindNode(data);
			if(pos == NULL)
				return false;
			LinkNode *cur=pHead->_next;
			while(cur->_next != pos)
			{
				cur=cur->_next;
			}
			cur->_next=pos->_next;
			delete pos;
			return true;
		}

		void Destroy()
		{
			if(pHead == NULL)
				return;
			LinkNode *cur=pHead->_next;
			while(cur)
			{
				LinkNode *del=cur;
				cur=cur->_next;
				delete del;
				del=NULL;
			}
			delete pHead;  //删除头结点
		}
		LinkNode *pHead;
};
/*创建测试固件：
 * 1：创建一个类继承自testing::Test。将其中的成员声明为protected:或是public:，因为我们想要从子类中存取固件成员。
 * 2：在该类中声明你计划使用的任何对象。
 * 3：如果需要，编写一个默认构造函数或者SetUp()函数来为每个测试准备对象。常见错误包括将SetUp()拼写为Setup()（小写了u）——不要让它发生在你身上。
 * 4：如果需要，编写一个析构函数或者TearDown()函数来释放你在SetUp()函数中申请的资源。要知道什么时候应该使用构造函数/析构函数，什么时候又应该使用SetUp()/TearDown()函数，阅读我们的FAQ。
 * 5：如果需要，定义你的测试所需要共享的子程序。*/

//必须在使用TEST_F之前定义好类
class TestLink:public testing::Test//1
{
	public:
		virtual void SetUp()//3
		{
			cout<<"SetUp"<<endl;
			for(int i=1;i<=5;i++){
				link.PushBack(i);
			}
		}
		virtual void TearDown()//4
		{
			cout<<"TearDown"<<endl;
			link.Destroy();
		}
		Link link;//2
};

//TEST_F:测试固件，在多个测试中使用同样的数据配置
//必须在TEST_F()中使用它之前，定义好这个测试固件类。
TEST_F(TestLink,PushBack)
{
	ASSERT_FALSE(link.pHead == NULL);
	link.PushBack(9);
	LinkNode *res=link.FindNode(9);
	ASSERT_FALSE(res == NULL);
}

TEST_F(TestLink,PopBack)
{
	for(int i=1;i<=5;i++){
		link.PopBack();
	}
}

TEST_F(TestLink,FindNode)
{
	ASSERT_TRUE(link.FindNode(3));
	ASSERT_TRUE(link.FindNode(2));
	ASSERT_TRUE(link.FindNode(4));
	ASSERT_TRUE(link.FindNode(5));
	ASSERT_TRUE(link.FindNode(1));
	ASSERT_FALSE(link.FindNode(7));
}

TEST_F(TestLink,Delete)
{
	ASSERT_FALSE(link.pHead == NULL);
	ASSERT_TRUE(link.Delete(3) == true);
	ASSERT_TRUE(link.Delete(9) == false);
}

int main(int argc,char *argv[])
{
	//testing::InitGoogleTest()函数负责解析命令行传入的Google Test标志，并删除所有它可以处理的标志。这使得用户可以通过各种不同的标志控制一个测试程序的行为。
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
