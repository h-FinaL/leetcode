#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (n == 0 || m == 0) 
			return 0;

		vector<int> v(n, 1);
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				v[j] = v[j - 1] + v[j];

		return v[n - 1];
	}
};