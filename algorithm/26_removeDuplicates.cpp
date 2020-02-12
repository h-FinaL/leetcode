#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();

		int result = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			while (i < nums.size() && nums[i - 1] == nums[i]) i++;
			if (i >= nums.size()) break;
			nums[result] = nums[i];
			result++;
		}
		nums.erase(nums.begin() + result, nums.end());

		return result;
	}
};