#include <iostream>
#include <vector>

/*
96. 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
*/

using namespace std;
class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] += dp[i - 1] * 2;
            for (int j = 1; j < i; j++)
                dp[i] += dp[i - j - 1] * dp[j - 1]; 
        }

        return dp[n - 1];
    }
};