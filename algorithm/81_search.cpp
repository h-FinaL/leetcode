#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			while (left < right && nums[left] == nums[right]) right--;
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] >= nums[left])
			{
				if (target < nums[mid] && target >= nums[left])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				if (target < nums[mid] || target >= nums[left])
					right = mid - 1;
				else
					left = mid + 1;
			}
		}

		return false;
	}
};