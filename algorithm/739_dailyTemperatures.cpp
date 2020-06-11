#include <iostream>
#include <vector>
#include <stack>

/*
739. 每日温度
根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。
如果之后都不会升高，请在该位置用 0 来代替。
*/

using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size());
		stack<int> stk;
		for (int i = 0; i < T.size(); i++)
		{
			while (!stk.empty() && T[stk.top()] < T[i])
			{
				res[stk.top()] = i - stk.top();
				stk.pop();
			}
			stk.push(i);
		}
		while (!stk.empty())
		{
			res[stk.top()] = 0;
			stk.pop();
		}
		return res;
	}
};