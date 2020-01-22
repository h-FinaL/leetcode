#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		if (nums.size() < 4 ) return result;

		int left = 0;
		int right;
		int m_left, m_right;
		int num;
		while (left < nums.size() - 3)
		{
			right = nums.size() - 1;
			while (right > left + 2)
			{
				m_left = left + 1;
				m_right = right - 1;
				while (m_left < m_right)
				{
					num = nums[left] + nums[right] + nums[m_left] + nums[m_right];
					if (num > target)
						do { m_right--; } while (m_right > m_left&& nums[m_right] == nums[m_right + 1]);
					else if (num < target)
						do { m_left++; } while (m_right > m_left&& nums[m_left] == nums[m_left - 1]);
					else
					{
						result.push_back(vector<int>{nums[left], nums[m_left], nums[m_right], nums[right]});
						do { m_right--; } while (m_right > m_left&& nums[m_right] == nums[m_right + 1]);
					}
				}
				do { right--; } while (right > left + 2 && nums[right] == nums[right + 1]);
			}
			do { left++; } while (left < nums.size() - 3 && nums[left] == nums[left - 1]);
		}

		return result;
	}

};