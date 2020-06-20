/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：set_interface.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _SET_INTERFACE_H
#define _SET_INTERFACE_H
//大顶堆：每个根结点值都比其字节点值大

#include <vector>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap {
	private:
		vector<T> data;

	public:
		MaxHeap() {

		 }

		MaxHeap(int capacity) {
	        	data = vector<T>(capacity);
		}

		//将无序的数组整理为有序的大顶堆
		MaxHeap(const vector<T> &array) {
		        data = array;
			//获取最后一个非叶子结点---父节点
			T lastParent = parent(array.size() - 1);
			while (lastParent >= 0) {
				//将父节点与其字节点比较交换
				siftDown(lastParent);
		                lastParent--;//依次比较所有父节点
			}
		}

		int size() {
			return data.size();
		}

		bool isEmpty() {
		        return data.empty();
			    }

		int parent(int index) {
		        assert(index > 0);      // 根节点没有父亲
			return (index - 1) / 2;
		}

	  	int leftChild(int index) {
		        return 2 * index + 1;
		}

	        int rightChild(int index) {
			return 2 * index + 2;
		}

		//添加结点
	 	void add(T value) {
			//将结点放入数组末尾
		        data.push_back(value);
			//与其父节点比较，依次上述，直到其比父节点小
			siftUp(data.size() - 1);
		}

	  	void siftUp(int k) {
			//当结点值大于其父节点，交换其值，并将结点上述
		        while (k > 0 && data[parent(k)] < data[k]) {
				swap(k, parent(k));
				k = parent(k);				         
		
			}
		}

	       void swap(int i, int j) {
			assert(i >= 0 && i < size() && j >= 0 && j < size());
			T t = data[i];
			data[i] = data[j];
			data[j] = t;
	       }

	      T findMax() {//寻找最大值--根结点
		        assert(size() > 0);
			return data[0];
	      }

	      T extractMax() {//取出最大值
		        T ret = findMax();//找到最大值

			swap(0, data.size() - 1);//将最大值与末尾值交换
			data.pop_back();
			siftDown(0);//下述将最后结点放入合适位置

			return ret;
							          
	      }

	        
	      void siftDown(int k) {//下述--与其字节点比较--注意下标范围
			       
		      while (leftChild(k) < data.size()) {
				int j = leftChild(k);
				//找到字节点较大值
				if (j + 1 < data.size() && data[j + 1] > data[j]) 
					j = rightChild(k); //j++ // data[j]是此时leftChild 和 rightChild中的最大值
				//父节点与较大值比较
				if (data[k] > data[j]) break;
				swap(k, j);
				k = j;//将父节点下标赋值为其字节点
		      }
		}

		T replace(T value) {
			T ret = findMax();
			data[0] = value;
			siftDown(0);
			return ret;
		}


};
	     #endif
