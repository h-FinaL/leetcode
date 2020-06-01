#include <iostream>
#include <vector>

/*
1431. 拥有最多糖果的孩子
对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。
注意，允许有多个孩子同时拥有 最多 的糖果数目。


*/

using namespace std;
class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = 0;
		for (int i = 0; i < candies.size(); i++)
			max = candies[i] > max ? candies[i] : max;
		vector<bool> res(candies.size(), false);
		for (int i = 0; i < candies.size(); i++)
		{
			if (candies[i] + extraCandies >= max)
				res[i] = true;
		}
		return res;
	}
};