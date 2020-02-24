#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int i = left;
		while (i <= right)
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[left]);
				i++;
				left++;
 			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[right]);
				do { right--; } while (right > 0 && nums[right] == 2);
			}
			else
				i++;
		}
	}
};