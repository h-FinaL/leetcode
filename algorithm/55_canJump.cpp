#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int max = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			max = max > nums[i] + i ? max : nums[i] + i;
			if (max >= nums.size() - 1)
				return true;
			else if (max <= i)
				return false;
		}

		return true;
	}
};