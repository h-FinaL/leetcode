#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int n[16];
		int i = 0;
		do
		{
			n[i] = x % 10;
			x = x / 10;
			i++;
		} while (x > 0);
		i--;
		for (int j = 0; j <= i; j++, i--)
		{
			if (n[j] != n[i])
				return false;
		}
		return true;
	}
};
