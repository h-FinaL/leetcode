#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int(*v)[2] = new int[2][2];
		v[1][0] = 0;
		v[1][1] = -prices[0];
		v[0][0] = 0;
		v[0][1] = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			int tmp1 = v[1][1];
			int tmp2 = v[1][0];
			int tmp3 = v[0][1];
			v[1][1] = max(v[1][1], -prices[i]);
			v[1][0] = max(v[1][0], tmp1 + prices[i]);
			v[0][1] = max(v[0][1], tmp2 - prices[i]);
			v[0][0] = max(v[0][0], tmp3 + prices[i]);
		}
		int result = v[0][0];
		delete[] v;
		return result;
	}
};