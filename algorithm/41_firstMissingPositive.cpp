#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty())
			return 1;

		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] > 0)
			{
				if (nums[i] > nums.size())
					nums[i] = 0;
				else if (nums[nums[i] - 1] != nums[i])
					swap(nums[i], nums[nums[i] - 1]);
				else if (i != nums[i] - 1 && nums[nums[i] - 1] == nums[i])
					nums[i] = 0;
				else
					break;
			}
		}

		int i = 0;
		for (; i < nums.size(); i++)
			if (nums[i] <= 0)
				break;

		return i + 1;
	}
};