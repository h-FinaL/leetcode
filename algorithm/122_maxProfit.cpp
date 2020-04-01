#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int result = 0;
		int i = 1;
		while (i < prices.size())
		{
			while (i < prices.size() && prices[i] < prices[i - 1])
				i++;
			int min = prices[i - 1];
			while (i < prices.size() && prices[i] >= prices[i - 1])
				i++;
			result += prices[i - 1] - min;
		}

		return result;
	}
};