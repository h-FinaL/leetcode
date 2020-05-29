#include <iostream>
#include <vector>
#include <algorithm>

/*
213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

*/

using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int n1 = rob(nums, 0, nums.size() - 1);
		int n2 = rob(nums, 1, nums.size());
		return max(n1, n2);
	}

	int rob(vector<int>& nums, int start, int end) {
		int dp1 = 0;
		int dp2 = 0;
		for (int i = start; i < end; i++)
		{
			int temp = dp1;
			dp1 = dp2;
			dp2 = std::max(dp2, temp + nums[i]);
		}

		return std::max(dp1, dp2);
	}
};