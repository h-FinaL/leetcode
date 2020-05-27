#include <iostream>
#include <string>
#include <vector>

/*
44. 通配符匹配
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
*/

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));
        dp[0][0] = 1;
        //对s[0]进行匹配 处理p[0] == '*' 的情况
        for (int x = 1; x < dp.size() && p[x - 1] == '*'; x++)
            dp[x][0] = 1;

        for (int x = 1; x < dp.size(); x++)
        {
            for (int y = 1; y < dp[0].size(); y++)
            {
                //当 *p = '*' 时，*(p - 1) == *(s - 1) 或 *(p - 1) == *s 说明后面全匹配 
                if (p[x - 1] == '*' && (dp[x - 1][y - 1] || dp[x - 1][y] == 1))
                    while (y < dp[0].size()) { dp[x][y] = 1; y++; }
                else if (p[x - 1] == '?' || p[x - 1] == s[y - 1])
                    dp[x][y] = dp[x - 1][y - 1];
            }
        }

        return dp[p.size()][s.size()];
    }

}; 