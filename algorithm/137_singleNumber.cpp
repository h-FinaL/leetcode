#include <iostream>
#include <vector>

/*
137. 只出现一次的数字 II
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

*/

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int once = 0, twice = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			once = (nums[i] ^ once) & (~twice);
			twice = (nums[i] ^ twice) & (~once);
		}
		return once;
	}
};
