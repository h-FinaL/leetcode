#include <iostream>

using namespace std;
 
class Solution {
public:
	int fib(int n) {
		if (n <= 1)
			return n;
		int n1 = 0, n2 = 1;
		int s = 1;
		for (int i = 2; i < n; i++)
		{
			if (s == 1)
			{
				n1 = (n1 + n2) % 1000000007;
				s = 2;
			}
			else if (s == 2)
			{
				n2 = (n1 + n2) % 1000000007;
				s = 1;
			}
		}

		return  (n1 + n2) % 1000000007;
	}
};