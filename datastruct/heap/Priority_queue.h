/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：Priority_queue.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include "set_interface.h"
#include "vector_heap.h"

template<typename T>
class PriorityQueue : public BaseQueue {
	private:
		MaxHeap<T> maxHeap;
	public:
		int getSize() {
			return maxHeap.size();
		}

		void enqueue(T value) {
			maxHeap.add(value);
		}

		T getFront() {
			return maxHeap.findMax();
		}

		T dequeue() {
			return maxHeap.extractMax();
		}

		bool isEmpty() {
			return maxHeap.isEmpty();
		}
};

#endif
