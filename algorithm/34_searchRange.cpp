#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1, -1 };
		if (nums.empty())
			return result;
		int left = 0;
		int right = nums.size() - 1;
		int mid;

		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}

		if (nums[right] == target)
			result[0] = right;
		else
			return result;

		left = right;
		right = nums.size() - 1;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] > target)
				right = mid;
			else
				left = mid + 1;
		}
		if (nums[left] == target)
			result[1] = left;
		else
			result[1] = left - 1;

		return result;
	}
};