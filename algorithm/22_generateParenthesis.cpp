#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0)
			return result;
		int stack = 0;
		char* s = new char[2 * n + 1];
		s[2 * n] = '\0';
		getParenthesis(result, s, 0, stack, n);

		delete [] s;
		return result;
	}

	void getParenthesis(vector<string>& result, char* s, int num, int stack, int n)
	{
		if (n <= 0)
		{
			while (stack > 0)
			{
				s[num] = ')';
				num++;
				stack--;
			}
			result.push_back(string(s));
			return;
		}
		if (n > 0)
		{
			if (stack > 0)
			{
				s[num] = ')';
				getParenthesis(result, s, num + 1, stack - 1, n);
			}

			s[num] = '(';
			getParenthesis(result, s, num + 1, stack + 1, n - 1);
			
		}
	}
};