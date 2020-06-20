/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：BinarySearch.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月20日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>

/*二分查找要求数据必须是有序的，且内存空间连续*/

int BinarySearch(vector<int>& nums,int n,int target);

int main()
{
	//vector<int> nums({1,1,2,3,4,5});
	//vector<int> nums({1,3,4,5,6,7,7,7,10,11});
	//vector<int> nums({1,3,4,5,6,7,8,9,9,9});
	//vector<int> nums({1,3,4,5,6,8,9,10});
	vector<int> nums({1,2,3,6,7,8,10});
	int index = BinarySearch(nums,nums.size(),3);
	cout << "index : " << index << endl;
	return 0;
}

int BinarySearch(vector<int>& nums,int n,int target)
{
#if 0
	int left = 0,right = n-1;

	while(left <= right){
#if 0
		int mid = (right+left)/2;
#else
		//两者之和可能溢出，使用差计算，将除2转换为位运算更好
		int mid = left+((right-left)>>1);
#endif
		if(nums[mid] > target)
			right = mid-1; 
		else if(nums[mid] < target)
			left = mid+1;
		else
			return mid;
	}
	return -1;
#else
	/*二分法的各种变种*/
#if 0
	//情况1：
	cout << "情况1：查找第一个值等于给定值的情况\n";
	/*查找第一个值等于给定值的情况
	 * 当中间值不是第一次出现的时候，则检查其前面值是否为该值，若是则right = mid-1*/
	//1 3 4 5 6 7 7 7 10 11----求7
	int left = 0,right = n-1;
	while(left <= right){
		int mid = left+((right-left)>>1);
		if(nums[mid] > target)
			right = mid-1;
		else if(nums[mid] < target)
			left = mid+1;
		else{
			if(mid==0 || nums[mid-1] != target)
				return mid;
			else//当存在多个给定值且获取第一个下标时，当中间值前面一个值与给定值相等时，需要将右指针向左边逼近
				right = mid-1;
		}
	}
	return -1;



	/*----------------------情况2：*/
	cout << "情况2：查找最后一个值等于给定值的情况\n";
	/*当中间值等于给定值时，且其后面还有与给定值相等的元素，获取最后一个元素下标*/
	//1 3 4 5 6 7 8 9 9 9----9
	int left = 0,right = n-1;
	while(left <= right){
		int mid = left+((right-left)>>1);
		if(nums[mid] > target)
			right = mid-1;
		else if(nums[mid] < target)
			left = mid+1;
		else{
			if(mid==0 || nums[mid+1] != target)
				return mid;
			else//当存在多个给定值且获取最后一个下标时，当中间值后面一个值与给定值相等时，需要将左指针向右边逼近
				left = mid+1;
		}
	}
	return -1;


	/*------------------------------情况3：*/
	cout << "情况3：查找第一个大于等于给定值的情况\n";
	//1 2 3 4 6 8 10----7
	int left = 0,right = n-1;
	while(left <= right){
		int mid = left+((right-left)>>1);
		if(nums[mid] >= target)//不断向目标逼近
		{
			if(mid==0 || nums[mid-1]<target)
				return mid;
			else
				right = mid-1;
		}
		else
			left = mid+1;
	}
	return -1;
#else
	/*---------------------情况4：*/
	cout << "情况4：查找最后一个小于等于给定值的情况\n";

	int left = 0,right = n-1;
	while(right >= left){
		int mid = left+((right-left)>>1);
		if(nums[mid] > target)
			right = mid-1;
		else{//小于等于target
			if(mid==n-1 || nums[mid+1]>target)//当下一个值大于target,则mid是最后一个小于等于target的值
				return mid;
			else
				left = mid+1;
		}
	}
	return -1;
#endif
#endif
}
