#include <iostream>
#include <vector>

/*
238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
*/

using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size());
		if (nums.empty())
			return res;
		res[nums.size() - 1] = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 1; i--)
		{
			res[i] = res[i + 1] * nums[i];
		}
		res[0] = res[1];
		int n = nums[0];
		for (int i = 1; i < nums.size() - 1; i++)
		{
			res[i] = n * res[i + 1];
			n = n * nums[i];
		}
		res[nums.size() - 1] = n;
		return res;
	}
};