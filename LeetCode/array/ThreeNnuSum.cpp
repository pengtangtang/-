/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：ThreeNnuSum.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*给定一个包含n个整数的数组nums，判断nums中是否存在三个元素a,b,c，使三数之和为0？找出所有满足条件且不重复的三元组
 * 实例：
 * 给定数组nums={-1,0,1,2,-1,-4};
 * 满足条件的三元数组集合如下：
 * [[-1,0,1],[-1,-1,2]]*/

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
	int a[] = {-1,0,1,2,-1,-4};
	vector<int> nums(a,a+5);
	vector<vector<int>> res = threeSum(nums);

	for(int i = 0;i < res.size();i++)
	{
		for(auto j:res[i])
			cout << j << ' ';
		cout << endl;
	}

}

vector<vector<int>> threeSum(vector<int>& nums)
{
#if 0
	/*思路1：暴力法----使用三层循环，完成所有可能的三个元素组合，且将结果从小到大放入集合，通过set去除相同的结果*/
	vector<vector<int> > res;//存放结果
	if(3 > nums.size())
		return res;
	set<vector<int> > ret;//去除重复
	for(int i = 0;i < nums.size()-2;i++)
	{
		for(int j = i+1;j < nums.size()-1;j++)
		{
			for(int k = j+1;k < nums.size();k++)
			{
				if(nums[i]+nums[j]+nums[k] == 0)
				{
					vector<int> tp;
					int a = (nums[i]<nums[j]?nums[i]:nums[j])<nums[k]?(nums[i]<nums[j]?nums[i]:nums[j]):nums[k];
					int b = (nums[i]>nums[j]?nums[i]:nums[j])>nums[k]?(nums[i]>nums[j]?nums[i]:nums[j]):nums[k];
					int c = -a-b;

					tp.push_back(a);
					tp.push_back(c);
					tp.push_back(b);
					ret.insert(tp);
				}
			}
		}
	}
	for(auto it:ret)
		res.push_back(it);
	return res;
#else
	/*思路二：排序加双指针-----首先将数组排序，定义的左右值与定植相加，等于0就记录三个值，小于0左指针向右移动，大于0右指针向左移动，定值右移，重复步骤*/
	vector<vector<int> > res;//存放结果
	if(3 > nums.size())
		return res;
	sort(nums.begin(),nums.end());
	int target;
	for(int i = 0;i < nums.size();i++){
		if(i>0 && nums[i]==nums[i-1]) continue;//若挨着的多个值相等，则取最右边的
		if((target=nums[i]) > 0) break;//如果定值已经大于0则直接结束

		int left = i+1;
		int right = nums.size()-1;
		while(left < right){
		if(nums[left]+nums[right]+target > 0)	left++;
		else if(nums[left]+nums[right]+target < 0) right--;
		else{
			res.push_back({target,nums[left],nums[right]});
			++left,--right;
			//当连续两个数相同时直接跳过，不需要重复操作,因为排序了，该步骤相当与去重
			while(left<right && nums[left]==nums[left-1])
				++left;
			while(left<right && nums[right+1]==nums[right])
				--right;
		}
		}
	}
	return res;
#endif
}
