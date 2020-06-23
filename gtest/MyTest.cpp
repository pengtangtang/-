/*===============================================================
 *   Copyright (C) 2020 All rights reserved.
 *   
 *   文件名称：MyTest.cpp
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

struct Node{
	int data;
	Node* next;
	Node(int d = 0):data(d),next(NULL)
	{}
};
class Link{
	public:
		Link()
		{
			m_pHead = new Node();
		}

		void pushBack(const int& data)
		{
			if(NULL == m_pHead)
				return ;
			Node* node = new Node(data);
			if(NULL == m_pHead->next)
				m_pHead->next = node;
			else{
				Node* curr = m_pHead;
				while(curr->next)
				{
					curr = curr->next;
				}
				curr->next = node;
			}
		}

		void popBack()//删除最后一个结点
		{
			if(NULL == m_pHead)
				return;
			if(NULL == m_pHead->next)
			{
				delete m_pHead;
			}else{
				Node* pre = NULL,*cur = m_pHead;
				while(cur->next)
				{
					pre = cur;
					cur = cur->next;
				}
				pre->next = NULL;
				delete cur;
			}
			
	}
	
	Node* findNode(const int& data)
	{
		if(NULL == m_pHead)
			return NULL;
		Node* node = m_pHead;
		while(node)
		{
			if(data == node->data)
				break;
			node = node->next;
		}
		if(NULL == node)
			return NULL;
		return node;
	}
	
	bool deleteNode(int data)
	{
		if(m_pHead == NULL)
			return false;

		Node* pos = findNode(data);
		if(NULL == pos)
			return false;
		Node* node = m_pHead;
		while(node->next != pos)
		{
			node = node->next;
		}
		node->next = pos->next;
		delete pos;
		pos = NULL;
		return true;
	}
	
	void destroyLink()
	{
		if(NULL == m_pHead)
			return;
		if(NULL == m_pHead->next)
		{	delete m_pHead;
			m_pHead = NULL;
		}
		else{
			while(m_pHead)
			{
				Node* curr = m_pHead;
				delete curr;
				curr = NULL;
				m_pHead = m_pHead->next;
			}
		}
	}




	Node* m_pHead;
};

class TestLink:public testing::Test
{
	public:
		virtual void SetUp()
		{
			cout << "SetUp\n";
			for(int i =1;i <= 5;i++){
			//	cout << i << endl;
				link.pushBack(i);
			}
		}

		virtual void TearDown()
		{
			cout << "TearDown\n";
			link.destroyLink();
		}

		Link link;
};

TEST_F(TestLink,PushBack)
{
	ASSERT_FALSE(link.m_pHead == NULL);
	link.pushBack(9);
	Node* res = link.findNode(8);
	ASSERT_TRUE(res == NULL);
}
TEST_F(TestLink,PopBack)
{
	for(int i = 1;i <= 5;i++)
		link.popBack();
}
TEST_F(TestLink,FindNode)
{
	ASSERT_TRUE(link.findNode(2));
	ASSERT_FALSE(link.findNode(6));
}

TEST_F(TestLink,DeleteNode)
{
	ASSERT_FALSE(link.m_pHead == NULL);
	ASSERT_TRUE(link.deleteNode(3) == true);
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
