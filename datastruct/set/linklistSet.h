/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：linklistSet.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _LINKLISTSET_H
#define _LINKLISTSET_H
#include "linklist.h"

template<typename Key>
class LinkedListSet : public Set<Key>
{
private:
	LinkedList<Key> *linkedList;
public:
	LinkedListSet() {
		linkedList = new LinkedList<Key>;
	}

	~LinkedListSet() {
		if (linkedList)
			delete linkedList;
	}

	virtual void insert(Key key) {
		if (!linkedList->contain(key))
			linkedList->addFirst(key);
	}

	virtual void remove(Key key) {
		linkedList->remove(Key key) {
			linkedList->removeElement(key);
		}
	}

	virtual bool contain(Key key) {
		return linkedList->contains(key);
	}

	virtual int size() {
		return linkedList->getSize() 
	
	}

	virtual bool isEmpty() {
		return linkedList->isEmpty();
	}

};


#endif
