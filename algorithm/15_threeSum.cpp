#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end()); 
		if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)
			return result;

		unordered_map<int, int> m;  //map存储对应位置
		m[nums[0]] = 0;
		for (int i = 1; i < nums.size(); i++)  //小于0重复的取最右边，大于0取最左边位置
			if (nums[i - 1] == nums[i] && nums[i] > 0)
				continue;
			else
				m[nums[i]] = i;

		if (m.find(0) != m.end() && m[0] >= 2 && nums[m[0] - 2] == 0) //三个为0的情况
			result.push_back(vector<int> {0, 0, 0});

		int left = 0, right = nums.size() - 1;
		int n;
		int position;
		while (nums[left] < 0) //第一个值从左端开始取值
		{
			while (nums[right] > 0) //第二个值从右端开始取值
			{
				n = -(nums[left] + nums[right]);  //计算第三个值
				if (m.find(n) != m.end()) 
				{
					position = m[n]; //通过map找到第三个值的位置
					if (position >= right) break; //如果位置在第二个值的右边则结束
					if (left < position && position < right) //位置在第一个值和第二个值中间成立
						result.push_back(vector<int> {nums[left], nums[right], n});
				}
				do { right--; } while (nums[right] == nums[right + 1]) ;
			}
			do { left++; } while (nums[left] == nums[left - 1]);
			right = nums.size() - 1;
		}

		return result;
	}
};
