#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int i_max = 1;
		int i_min = 1;
		int max = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				std::swap(i_max, i_min);
			i_max = std::max(i_max * nums[i], nums[i]);
			i_min = std::min(i_min * nums[i], nums[i]);

			max = std::max(i_max, max);
		}

		return max;
	}
};