#include <iostream>
#include <vector>
#include <algorithm>

/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
*/

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int i1 = 0;
		int i2 = 0;
		for (auto& i : nums)
		{
			int temp = i1;
			i1 = i2;
			i2 = std::max(i2, temp + i);
		}

		return std::max(i1, i2);
	}

};