/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：RemoveEle2.cpp
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

/*数组为无序：删除给定元素，返回删除后的长度*/

int removeEle(vector<int>& nums,int n)
{
	if(nums.size() == 0)
		return -1;
	//j记录长度并交换元素，i遍历数组
	int j = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] != n)
		{
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}
int main()
{
	vector<int> nums({1,2,2,3});
	int len = removeEle(nums,2);
	cout << "len = " << len;
	return 0;
}
