#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int result = 0;
		int min = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			while (i < prices.size() && prices[i] <= prices[i - 1]) { i++; }
			min = prices[i - 1] < min ? prices[i - 1] : min;
			while (i < prices.size() && prices[i] >= prices[i - 1]) { i++; }
			result = (prices[i - 1] - min) > result ? (prices[i - 1] - min) : result;
		}

		return result;
	}
};