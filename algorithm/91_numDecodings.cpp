#include <iostream>
#include <vector>

/*
91. 解码方法
*/

using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		vector<int> dp(s.size() + 1, 0);
		char num1[2] = { 0 };
		char num2[3] = { 0 };
		if (s.size() > 0)
		{
			num1[0] = s[0];
			dp[1] = (atoi(num1) != 0);
			dp[0] = 1;
		}
		for (int i = 1; i < s.size(); i++)
		{
			num1[0] = s[i];
			num2[0] = s[i - 1];
			num2[1] = s[i];
			int n1 = atoi(num1);
			int n2 = atoi(num2);
			if (n1 != 0)
				dp[i + 1] += dp[i];
			if (10 <= n2 && n2 <= 26)
				dp[i + 1] += dp[i - 1];
		}

		return dp[s.size()];
	}
};