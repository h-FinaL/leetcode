#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		vector<int> v(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
		{
			if (v[nums[i]] == 1)
				return nums[i];
			else
				v[nums[i]]++;
		}

		return -1;
	}
    
	int findRepeatNumber1(vector<int>& nums) {
		int i = 0;
		while (i < nums.size())
		{
			int p = nums[i];
			if (i != p && nums[p] == nums[i])
				return nums[i];
			else if (nums[p] != nums[i])
				swap(nums[p], nums[i]);
			else
				i++;
		}

		return -1;
	}
};