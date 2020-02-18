#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
			return;

		int i = nums.size() - 2;
		while (i >= 0)
		{
			if (nums[i] < nums[i + 1])
				break;
			else
				i--;
		}
		if (i < 0)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		int j = nums.size() - 1;
		while (j > i)
		{
			if (nums[j] > nums[i])
			{
				swap(nums[j], nums[i]);
				break;
			}
			else
				j--;
		}
		if (i < nums.size() - 2)
			sort(nums.begin() + i + 1, nums.end());
	}
};