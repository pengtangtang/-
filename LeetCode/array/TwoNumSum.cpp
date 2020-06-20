/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：TwoNumSum.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年06月19日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*给定一个整数数组nums和一个目标值target,请你在该数组中找出和为目标值的那两个整数，并返回他们的下标。
 * 你可以假设每种输入只会对应一个答案。但你不能重复利用数组中同样的元素.
 * 实例：
 * 给定nums=[2,7,11],target=9
 * 因为nums[0]+nums[1]=2+7=9
 * 所以返回[0,1]*/

vector<int> twoSum(vector<int>& nums,int target);
int main()
{
	vector<int> num;
	num.push_back(2);
	num.push_back(7);
	num.push_back(11);
	num.push_back(15);
	int target = 9;
	//vector<int> sum = twoSum(num,target);
	vector<int> sum(twoSum(num,target));

	for(int i = 0;i < sum.size();i++)
		cout << sum[i] << ' ';
	cout << endl;
	return 0;
}
vector<int> twoSum(vector<int>& nums,int target)
{
#if 0
	/*思路一：暴力法---使用双层循环将所有可能的两两组合之和与target比较若相等则返回两元素下标*/
	int i = 0;
	int j = 0;
	for(;i < nums.size()-1;i++){
		for(j = i+1;j < nums.size();j++){
			if(nums[i]+nums[j] == target)
				return {i,j};
		}
	}
	return {i,j};
#else
	/*思路二：hash---使用unorder_map,循环遍历数组，每得到一个元素A，就去hash表中查找是否存在target-A*/
	vector<int> res;
	unordered_map<int,int> hash_map;
	for(int i = 0;i < nums.size();i++){
		int another = target - nums[i];
		if(hash_map.count(another)){
		//	res = vector<int>(hash_map[another],i),该句表达的是hash_map[another]个i.
#if 1
			res = vector<int>({hash_map[another],i});//这样才对
#else
			res.push_back(hash_map[another]);
			res.push_back(i);
#endif
			return res;
		}
		hash_map[nums[i]] = i;
	}
	return res;
#endif
}


