#include <iostream>

/*

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

*/

class Solution {
public:
	int reverse(int x) {
		int max = -1 ^ (1 << 31);
		int min = 1 << 31;
		int result = 0;
		while (x != 0)
		{
			if (max / 10 < result || ((max / 10 == result) && (max % result) < (x % 10)))
			{
				result = 0;
				break;
			}
			else if (min / 10 > result || ((min / 10 == result) && (max % result < x % 10)))
			{
				result = 0;
				break;
			}
			result = x % 10 + result * 10;
			x = x / 10;
		}
		return result;
	}
};