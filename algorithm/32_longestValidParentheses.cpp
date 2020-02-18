#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() <= 1) return 0;
		
		int maxLen = 0;
		stack<int> stack;
		stack.push(-1);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stack.push(i);
			}
			else
			{
				stack.pop();
				if (stack.empty())
					stack.push(i);
				else
				{
					int len = i - stack.top();
					maxLen = maxLen > len ? maxLen : len;
				}
			}
		}

		return maxLen;
	}
};