/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：MaxSubSum.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月20日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <cmath>

/*给定一个整数数组nums，找到一个具有做大和的连续子数组，返回其最大值
 * 实例：
 * [-2,1,-3,4,-1,2,1,-5,4]
 * [4,-1,2,1]为所求结果*/

/*1：假设第一个元素为最终返回的值，定位result
 * 2:遍历数组寻找大于0的数，保留当前sum值并累加，若当前元素小于0直接赋值给sum
 * 3：比较当前sum和result,将较大值赋给result*/

int maxSubArray(vector<int>& nums){
	int result = nums[0];
	int sum = 0;
	for(int num : nums){
		if(sum > 0)
			sum += num;
		else
			sum = num;
		result = max(result,sum);
	}
	return result;
	
}
