#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		while (i >= 0 && numPlusOne(digits[i])) { i--; }
		if (i < 0)
			digits.insert(digits.begin(), 1);

		return digits;
	}

	int numPlusOne(int& a)
	{
		if (a < 9)
		{
			a = a + 1;
			return 0;
		}
		else
		{
			a = 0;
			return 1;
		}
	}
};