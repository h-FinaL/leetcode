#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<int> v(n);
		vector<vector<int>> result(n);
		for (int i = 0; i < n; i++)
			result[i] = v;

		int num = 1;
		int x1 = 0, y1 = 0;
		int x2 = n - 1, y2 = n - 1;
		while (x1 < x2)
		{
			int x = x1, y = y1;
			for (; y < y2; y++, num++)
				result[x][y] = num;
			for (; x < x2; x++, num++)
				result[x][y] = num;
			for (; y > y1; y--, num++)
				result[x][y] = num;
			for (; x > x1; x--, num++)
				result[x][y] = num;
			x1++; y1++;
			x2--; y2--;
		}
		if (x1 == x2 && y1 == y2)
			result[x1][y1] = num;

		return result;
	}
};
