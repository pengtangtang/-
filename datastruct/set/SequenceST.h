/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：SequenceST.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _SEQUENCEST_H
#define _SEQUENCEST_H
//顺序查找表--主要用于查找
//动态查找---动态链表
#include <iostream>
#include <cassert>
#include "set_interface.h"
using namespace std;
template<typename Key,typename Value>
classm SequenceST{
	private:
		struct Node {
			Key key;
			Value value;
			Node* next;

			Node(Key k,Value v) {
				value = v;
				key = k;
				next = NULL;
			}
		};
		Node* head;
		int count;
	public:
		SequenceST() {
			head = NULL;
			count = 0;
		}

		~SequenceST() {
			while (head) {
				Node* node = head;
				head = head->next;
				delete node;
				count--;
			}
			assert(head==NULL && count==0);
		}

		int size() {
			return count;
		}

		bool isEmpty() {
			return 0 == count;
		}

		void insert(Key key,Value value) {
			Node* node = head;
			while (head) {
				if (key == node->key) {
					node->value = value;
					return;
				}
				node = node->next;
			}
			Node* newNode = new Node(key,value);
			newNode->next = head;
			head = newNode;
			count++;
		}

		void set(Key key,Value value) {
			Node* node = head;
			while (node) {
				if (key == node->key) {
					node->value = value;
					return ;
				}
				node = node->next;
			}
		}

		bool contain(Key key) {
			Node* node = head;
			while (node) {
				if (key == node->key) {
					node->value = value;
					return true;
				}
				node = node->next;
			}
			return false;
			
		}

		Value* search(Key key) {
			Node* node = head;
			while (node) {
				if (key == node->key) {
					return &node->value;;
				}
				node = node->next;
			}
			return NULL;
		}

		Value* remove(Key key) {
			if (head == NULL) return NULL;

			if (key == head->key){
				Node* delNode = head;
				head = head->next;
				count--;
				return &delNode->value;
			}

			Node* node = head;
			while (node->next && node->next->key != key)
				node = node->next;
			if (node->next) {
				Node* delNode = node->next;
				node->next = delNode->next;
				count--;
				return &delNode->value;
			}
		}
};

#endif
