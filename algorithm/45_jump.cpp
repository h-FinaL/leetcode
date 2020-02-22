#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2) return 0;

		int result = 0;
		vector<int> v;

		int i = 0;
		for (; i < nums.size(); i++)
			v.push_back(i + nums[i]);
		if (nums[0] >= nums.size() - 1)
			return 1;

		i = 0;
		while (i < nums.size() - 1)
		{
			int j = i + 1;
			int maxJump = 0;
			int max = 0;
			for (; j <= i + nums[i]; j++)
			{
				if (v[j] >= nums.size() - 1)
				{
					result = result + 2;
					return result;
				}
				else if(v[j] > max)
				{
					maxJump = j;
					max = v[j];
				}
			}
			if (maxJump == 0) return 0;
			i = maxJump;
			result++;
		}

		return result;
	}
};