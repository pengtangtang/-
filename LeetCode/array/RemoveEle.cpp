/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：RemoveEle.cpp
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

/*给定一个排序数组，你需要在原地删除重复元素，使得每个元素只出现一次，返回移除后数组的新长度，不要使用额外的数组空间，你必须在原地修改数组并在使用o(1)额外空间的条件下完成
 * 实例：
 * 给定数组nums=[1,1,2]
 * 函数应该返回新的长度2，并且原数组nums的前两个元素被修改为1，2*/

int removeEle(vector<int>& nums);
int main()
{
	int n[] = {1,2,3,3,4};
	vector<int> nums(n,n+sizeof(n)/sizeof(int));
	//vector<int> nums({1,1,2});
	int si = removeEle(nums);
	cout << "size: " << si << endl;
	return 0;
}

int removeEle(vector<int>& nums)
{
	/*思路1:快慢指针-----定义满指针i快指针j，当两个值相等时快指针向前移动，当两值不等时，nums[i+1]=nums[j],i++,j++*/
	if(nums.size()==0)
		return 0;
	int i = 0;
	for(int j = 1;j < nums.size();j++)
	{
		if(nums[i]!=nums[j])
		{
			if(j-i > 1){//去除多余的赋值操作，当排序数组没有重复元素
				nums[i+1] = nums[j];
			}
			i++;
		}
	}
	cout << "i: " << i << endl;
	return i+1;
}
