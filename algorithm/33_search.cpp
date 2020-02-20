#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;

		int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right) / 2;

		while (left <= right)
		{
			if (nums[mid] == target)
				return mid;
			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				if (target >= nums[left] || target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;  
			}
			mid = (left + right) / 2;
		}

		return -1;
	}
};