#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;

		for (int i = 0; i < nums.size(); i++)
		{
			int size = result.size();
			for (int j = 0; j < size; j++)
			{
				result.push_back(result[j]);
				result[size + j].push_back(nums[i]);
			}
			result.push_back(vector<int>{nums[i]});
		}

		result.push_back(vector<int>());

		return result;
	}

};