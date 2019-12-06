#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = 0;
		map<int, int> m;
		vector<int> result;
		for (auto begin = nums.begin(); begin != nums.end(); begin++)
		{
			if (m.find(target - *begin) != m.end())
			{
				result.push_back(m[target - *begin]);
				result.push_back(n);
				break;
			}
			else
			{
				m[*begin] = n;
				n++;
			}
		}
		return result;
	}
};