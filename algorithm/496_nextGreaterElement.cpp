#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

/*
496. 下一个更大元素 I
给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
如果不存在，对应位置输出 -1 。

*/

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m;
		stack<int> stk;
		stk.push(INT_MAX);
		for (auto& i : nums2)
		{
			while (i > stk.top())
			{
				m[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}
		while (!stk.empty())
		{
			m[stk.top()] = -1;
			stk.pop();
		}
		vector<int> result;
		for (auto& i : nums1)
			result.push_back(m[i]);
		return result;
	}
};