#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> v;
		sort(nums.begin(), nums.end());

		subsetsWithDup(nums, 0, v, result);

		return result;
	}

	void subsetsWithDup(vector<int>& nums, int start, vector<int>& v, vector<vector<int>>& result)
	{
		result.push_back(v);
		for (int i = start; i < nums.size(); i++)
		{
			if (i > start&& nums[i - 1] == nums[i]) continue;
			v.push_back(nums[i]);
			subsetsWithDup(nums, i + 1, v, result);
			v.pop_back();
		}
	}
};