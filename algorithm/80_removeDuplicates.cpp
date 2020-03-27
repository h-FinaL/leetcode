#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = 0;
		int i = 0;
		int n = 0;
		while (i < nums.size())
		{
			if (n < 2)
			{
				nums[len] = nums[i];
				i++;
				len++;
				n++;
			}
			while (i < nums.size() && nums[i] == nums[i - 1] && n == 2)
				i++;
			if (i < nums.size() && nums[i] != nums[i - 1])
				n = 0;
		}

		return len;
	}
};