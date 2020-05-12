#include <iostream>
#include <vector>
#include <stack>

/*
456. 132模式
给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：
当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
*/

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3)
			return false;
		vector<int> mins(nums.size());
		int min = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < min)
				min = nums[i];
			mins[i] = min;
		}
		stack<int> stk;
		stk.push(INT_MAX);
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			while (stk.top() <= mins[i])
				stk.pop();
			if (nums[i] > stk.top())
				return true;
			stk.push(nums[i]);
		}
		return false;
	}
}