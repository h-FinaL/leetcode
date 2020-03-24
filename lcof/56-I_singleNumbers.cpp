#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> result(2, 0);
		int t = 0;
		for (int i = 0; i < nums.size(); i++)
			t = t ^ nums[i];
		t = t & (-t);
		for (int i = 0; i < nums.size(); i++)
		{
			if ((t & nums[i]) == t)
				result[0] = result[0] ^ nums[i];
			else
				result[1] = result[1] ^ nums[i];
		}

		return result;
	}
};