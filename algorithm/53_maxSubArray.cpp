#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int sum = nums[0];
		int maxSum = sum;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] + sum < nums[i])
				sum = nums[i];
			else
				sum = sum + nums[i];

			maxSum = sum > maxSum ? sum : maxSum;
		}

		return maxSum;
	}
};