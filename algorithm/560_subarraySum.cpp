#include <iostream>
#include <vector>
#include <unordered_map>

/*
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
*/

using namespace std;

class Solution {
public:
	//边遍历边查找,利用 key = total - k查找
	int subarraySum(vector<int>& nums, int k) {
		int result = 0;
		unordered_map<int, int> m;
		m[0] = 1;
		int total = 0;
		for (auto& i : nums)
		{
			total += i;
			if (m.find(total - k) != m.end())
				result += m[total - k];
			m[total]++;
		}
		return result;
	}

	//第一次完成,先遍历，key = total + k查找
	int subarraySum1(vector<int>& nums, int k) {
		int result = 0;
		unordered_map<int, int> m;
		vector<int> v(nums.size() + 1, 0);
		m[0] = 1;
		int total = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			total += nums[i];
			m[total]++;
			v[i + 1] = total;
		}
		for (auto& i : v)
		{
			m[i]--;
			if (m.find(k + i) != m.end())
				result += m[k + i];
		}
		return result;
	}
};