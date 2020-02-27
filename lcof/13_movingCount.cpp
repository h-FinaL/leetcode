#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<int>> vv(m, vector<int>(n, 0));

		return  movingCount(m, n, k, 0, 0, vv);
	}

	int movingCount(int m, int n, int k, int x, int y, vector<vector<int>>& vv)
	{
		if (vv[x][y] == 1)
			return 0;

		if (!calc(x, y, k))
			return 0;

		int sum = 1;
		vv[x][y] = 1;
		if (x > 0)
			sum += movingCount(m, n, k, x - 1, y, vv);
		if (x < m - 1)
			sum += movingCount(m, n, k, x + 1, y, vv);
		if (y > 0)
			sum += movingCount(m, n, k, x, y - 1, vv);
		if (y < n - 1)
			sum += movingCount(m, n, k, x, y + 1, vv);
		

		return sum;
	}

	bool calc(int x, int y, int k)
	{
		 return (x % 10 + y % 10 + 
			 (x / 10) % 10 + 
			 (y / 10) % 10 + 
			 (x /100) % 10 + (y /100) % 10) <= k;
	}
};