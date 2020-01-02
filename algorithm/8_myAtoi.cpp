#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int MAX = -1 ^ (1 << 31);
		int MIN = 1 << 31;
		enum statuses {NORMAL, POSITIVE, NEGATIVE, END};
		int status = NORMAL;
		int result = 0;
		int n;
		for (int i = 0; i < str.length(); i++)
		{
			switch (status)
			{
			case NORMAL:
				if (str[i] == ' ')
					continue;
				else if (str[i] == '-')
					status = NEGATIVE;
				else if (str[i] == '+')
					status = POSITIVE;
				else if (48 <= str[i] && str[i] <= 57)
				{
					result = str[i] - 48;
					status = POSITIVE;
				}
				else
					status = END;
				break;
			case POSITIVE:
				if (48 > str[i] || str[i] > 57)
				{
					status = END;
					break;
				}
				n = str[i] - 48;
				if (MAX / 10 > result || (MAX / 10 == result && n <= 7))
					result = result * 10 + n;
				else
				{
					result = MAX;
					status = END;
				}
				break;
			case NEGATIVE:
				if (48 > str[i] || str[i] > 57)
				{
					status = END;
					break;
				}
				n = -(str[i] - 48);
				if (MIN / 10 < result || (MIN / 10 == result && n >= -8))
					result = (result) * 10 + n;
				else
				{
					result = MIN;
					status = END;
				}
				break;
			}
			if (status == END)
				break;
		}
		return result;
	}
};