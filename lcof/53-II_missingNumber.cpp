#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0, right = nums.size();
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == mid)
				left = mid + 1;
			else
				right = mid;
		}

		return left;
	}
};