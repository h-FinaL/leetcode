#include <iostream>

using namespace std;
 
class Solution {
public:
	int lastRemaining(int n, int m) {
		int k = 0;
		for (int i = 2; i <= n; i++) {
			k = (k + m) % i;
		}
		return k;
	}
};