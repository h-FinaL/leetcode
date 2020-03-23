#include <iostream>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		int result = a ^ b;
		int i = (unsigned int)(a & b) << 1;
		while (i != 0)
		{
			int i_ = i;
			i = (unsigned int)(result & i) << 1;
			result = result ^ i_;
		}

		return result;
	}
};