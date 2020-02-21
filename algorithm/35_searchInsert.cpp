#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid;
		}

		if (left == nums.size() - 1 && nums[left] < target)
			return left + 1;
		else
			return left;
	}
};