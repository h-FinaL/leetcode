#include <iostream>
#include <vector>

/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

*/

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++)
			result = nums[i] ^ result;
		return result;
	}
};