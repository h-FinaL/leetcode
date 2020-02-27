#include <iostream>

using namespace std;
 
class Solution {
public:
	int numWays(int n) {
		if (n == 0) return 1;
		if (n <= 2) return n;
		int n1 = 1, n2 = 2;
		int nx = 1;
		for (int i = 3; i < n; i++)
		{
			if (nx == 1)
			{
				n1 = (n1 + n2) % 1000000007;
				nx = 2;
			}
			else if (nx == 2)
			{
				n2 = (n1 + n2) % 1000000007;
				nx = 1;
			}
		}

		return (n1 + n2) % 1000000007;
	}
};