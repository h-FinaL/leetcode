#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int cuttingRope(int n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		long result = 1;
		int num = n / 3;
		if (n % 3 == 1)
		{
			result = 4;
			num--;
		}
		else if (n % 3 == 2)
			result = 2;
		for (int i = 0; i < num; i++)
		{
			result = (result * 3) % 1000000007;
		}

		return result;
	}
};