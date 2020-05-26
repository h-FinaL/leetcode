#include <iostream>
#include <vector>

/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
*/

using namespace std;

class Solution {
public:
    //二分查找法
	//时间复杂度为O(n*log(n))
	//空间复杂度为O(1)
	//不改变原数组
	int findDuplicate(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int result = right;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			int n = 0;
			for (int i = 0; i < nums.size(); i++)
				if (nums[i] < mid + 1) n++;
			if (n < mid + 1)
				left = mid + 1;
			else
			{
				right = mid;
				result = right;
			}
		}

		return result;
	}

	//时间复杂度为O（1）
	//空间复杂度为O（1）
	//但改变原始数组
	int findDuplicate1(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			while (i != nums[i] - 1)
			{
				if (nums[i] == nums[nums[i] - 1])
					return nums[i];
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		return -1;
	}
};