#include <iostream>
#include <unordered_map>

using namespace std;
 
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty()) return 0;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m[nums[i]] == 2) m.erase(nums[i]);
			else m[nums[i]]++;
		}
		return m.begin()->first;
	}
};