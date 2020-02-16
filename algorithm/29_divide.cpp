#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		int sig = (int)(dividend ^ divisor) >= 0 ? 1 : -1;
		if (divisor > 0) divisor = -divisor;
		if (dividend > 0) dividend = -dividend;
		int result = 0;

		while (dividend <= divisor)
		{
			int n = 1;
			int m = divisor;
			while (dividend - m < m)
			{
				n = n + n;
				m = (unsigned int)m << 1;
			}

			if (dividend - m == m)
			{
				result = n + n;
				break;
			}
			else
			{
				result = result - n;
				dividend = dividend - m;
			}
		}
		

		if (sig == 1)
			if (result < INT_MIN + 1) result = INT_MAX;
			else result = -result;

		return result;
	}
};