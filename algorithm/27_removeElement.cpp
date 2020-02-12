#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			while (i < nums.size() && nums[i] == val) i++;
			if (i >= nums.size()) break;
			nums[result] = nums[i];
			result++;
		}

		return result;
	}
};