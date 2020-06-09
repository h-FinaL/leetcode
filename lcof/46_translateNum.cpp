#include <iostream>
#include <vector>

/*
面试题46. 把数字翻译成字符串
*/

using namespace std;

class Solution {
public:
    //第二次实现 动态规划
	int translateNum1(int num) {
		if (num == 0)
			return 1;
		stack<int> stk;
		while (num)
		{
			stk.push(num % 10);
			num = num / 10;
		}
		int dp1 = 1, dp2 = 0;
		int pre;
		if (!stk.empty())
		{
			pre = stk.top();
			dp2 = 1;
			stk.pop();
		}
		while (!stk.empty())
		{
			int tmp = dp2;
			int n = stk.top() + pre * 10;
			if (10 <= n && n <= 25)
			{
				dp2 += dp1;
			}
			pre = stk.top();
			stk.pop();
			dp1 = tmp;
		}
		return dp2;
	}

    int translateNum(int num) {
        vector<int> n;
        while (num > 0)
        {
            n.push_back(num % 10);
            num = num / 10;
        }
        return translateNum(n, n.size() - 1);
    }

    int translateNum(vector<int>& n, int i)
    {
        if (i < 1) return 1;
        int n1 = n[i];
        int n2 = n1 * 10 + n[i - 1];
        if (n1 > 0 && n2 < 26)
            return translateNum(n, i - 1) + translateNum(n, i - 2);
        else
            return translateNum(n, i - 1);
    }
};