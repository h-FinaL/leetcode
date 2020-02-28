#include <iostream>

using namespace std;
 
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) 
			return 1;
		double result = 1;
		long ln = n;
		if (ln < 0)
		{
			ln = -ln;
			x = 1 / x;
		}
		
		while (ln > 0)
		{
			if (ln & 1)
				result = result * x;
			ln = ln >> 1;
			x = x * x;
		}

		return  result;
	}
};