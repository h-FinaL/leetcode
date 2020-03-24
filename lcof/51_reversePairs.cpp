#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> tmp(nums.size(), 0);
		return mergeSort(nums, tmp, 0, nums.size() - 1);
	}

	int mergeSort(vector<int>& nums, vector<int>& tmp, int start, int end)
	{
		if (start == end)
			return 0;
		int mid = start + (end - start) / 2;
		int n = 0;
		int n1 = mergeSort(nums, tmp, start, mid);
		int n2 = mergeSort(nums, tmp, mid + 1, end);
		int i = start;
		int p1 = start;
		int p2 = mid + 1;
		while (p1 <= mid && p2 <= end)
		{
			if (nums[p1] > nums[p2])
			{
				tmp[i] = nums[p2];
				n = n + mid - p1 + 1;
				i++; p2++;
			}
			else
			{
				tmp[i] = nums[p1];
				i++; p1++;
			}
		}
		while (p1 <= mid) { tmp[i] = nums[p1]; i++; p1++; }
		while (p2 <= end) { tmp[i] = nums[p2]; i++; p2++; }
		i = start;
		p1 = start;
		while (i <= end) { nums[p1] = tmp[i]; i++; p1++; }
		return n1 + n2 + n;
	}
};