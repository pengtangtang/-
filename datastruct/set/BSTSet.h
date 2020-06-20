/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：BSTSet.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _BSTSET_H
#define _BSTSET_H
#include "BST.h"
#include "set_interface.h"

template<typename Key>
class BSTSet : public Set<Ket> {
	private:
		BST<Key,Key> bst;
	public:
		virtual void insert(Key key) override {
			bst.insert(key,key);
		}

		virtual void remove(Key key) override {
			bst.remove(key);
		}

		virtual bool contain(Key key) override {
			bst.contain(key);
		}

		virtual int size() override {
			bst.size();
		}

		virtual bool isEmpty() override {
			bst.isEmpty();
		}
}
#endif
