#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int left = 0, right = nums.size() - 1;
		int sum;
		while (left < right)
		{
			sum = nums[left] + nums[right];
			if (sum == target)
			{
				result.push_back(nums[left]);
				result.push_back(nums[right]);
				break;
			}
			else if (sum < target)
				++left;
			else
				--right;
		}

		return result;
	}
};