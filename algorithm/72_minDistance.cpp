#include <iostream>
#include <vector>
#include <algorithm>

/*
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

	插入一个字符
	删除一个字符
	替换一个字符

*/

using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int x = 0; x < dp.size(); x++)
			dp[x][0] = x;
		for (int y = 0; y < dp[0].size(); y++)
			dp[0][y] = y;
		for (int x = 1; x < dp.size(); x++)
		{
			for (int y = 1; y < dp[0].size(); y++)
				dp[x][y] = min(dp[x - 1][y - 1] + (word1[x - 1] != word2[y - 1] ),
					min(dp[x - 1][y], dp[x][y - 1]) + 1);
		}

		for (int x = 0; x < dp.size(); x++)
		{
			for (int y = 0; y < dp[0].size(); y++)
				std::cout << dp[x][y] << " ";
			std::cout << std::endl;
		}

		return dp[word1.size()][word2.size()];
	}
};