/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test_heap.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月14日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "vector_heap.h"
#include "Priority_queue.h"

double testHeap(const vector<int>& testData,bool isHeapity)
{
	time_t startTime = clock();
	MaxHeap<int> *maxHeap;
	if (isHeapity)
		maxHeap = new MaxHeap<int>(testData);
	else {
		maxHeap = new MaxHeap<int>();
		for (auto num : testData)
			maxHeap->add(num);
	}
	vector<int> res(testData.size());
	for (int i = 0;i < testData.size();i++)
		res[i] = maxHeap->extractMax();

	for (int i = 0;i < testData.size();i++)
		if (res[i-1] < res[i])
			cout << "error\n";
	cout << "success\n";
	delete maxHeap;

	time_t endTime = clock();
	return double(endTime-startTime)/CLOCKS_PER_SEC;
}

int mian() {
	int n = 100;
	vector<int> testData(n);

	for (int i = 0;i < n;i++) {
		int r = rand()%(INT_MAX+1);
		testData.push_back(r);
	}

	double time1 = testHeap(testData,false);
	cout << "without heapity " << time1 << " s" << endl;

	double time2 = testHeap(testData,true);
	cout << "without heapity " << time2 << " s" << endl;
}
