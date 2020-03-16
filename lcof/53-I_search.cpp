#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start, end;
		int left = 0, right = nums.size();
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		start = left;
		left = 0, right = nums.size();
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] <= target)
				left = mid + 1;
			else
				right = mid;
		}
		end = left;
		return end - start;
	}
};