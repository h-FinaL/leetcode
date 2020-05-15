#include <iostream>
#include <vector>

/*
260. 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

*/

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int bitmask = 0;
		for (int& i : nums)
			bitmask = bitmask ^ i;
		int diff = bitmask & (-bitmask);
		int n1 = 0;
		for (int& i : nums)
		{
			if (i & diff)
				n1 = n1 ^ i;
		}
		int n2 = bitmask ^ n1;
		return { n1 , n2 };
	}
};