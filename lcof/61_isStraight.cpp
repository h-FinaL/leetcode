#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int zeroNum = 0;
		int i = 1;
		for (; i < nums.size(); ++i)
		{
			if (nums[i - 1] == 0)
				zeroNum++;
			else if (nums[i] - nums[i - 1] > 0 && nums[i] - nums[i - 1] <= zeroNum + 1)
				zeroNum = zeroNum - (nums[i] - nums[i - 1] - 1);
			else
				break;
		}

		if (i == nums.size())
			return true;
		else
			return false;
	}
};