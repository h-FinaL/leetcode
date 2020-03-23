#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		int i = str.find_first_not_of(' ');
		if (i < 0) return 0;
		int result = 0;
		int isNegative = 0;
		if (str[i] == '-')
		{
			isNegative = 1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (i < str.size() && '0' <= str[i] && str[i] <= '9')
		{
			int n = -(str[i] - '0');
			int a = INT_MIN - result * 10;
			if (INT_MIN / 10 > result || INT_MIN - result * 10 >= n)
			{
				result = INT_MIN;
				break;
			}
			else
				result = result * 10 + n;
			i++;
		}

		if (isNegative == 0)
		{
			if (result == INT_MIN)
				return INT_MAX;
			else
				return -result;
		}
		else
			return result;
	}
};