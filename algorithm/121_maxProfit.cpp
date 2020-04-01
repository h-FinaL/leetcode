#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int min = prices[0];
		int result = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > min)
				result = (prices[i] - min) > result ? (prices[i] - min) : result;
			else if (prices[i] < min)
				min = prices[i] < min ? prices[i] : min;
		}

		return result;
	}
};