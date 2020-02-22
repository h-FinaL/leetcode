#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return vector<int>();
		if (matrix.size() == 1) return matrix[0];

		int height = matrix.size();
		int width = matrix[0].size();
		vector<int> result(height * width);

		int x1 = 0, y1 = 0;
		int x2 = height - 1, y2 = width - 1;

		int x, y;

		int n = 0;
		while (y1 < y2 && x1 < x2)
		{
			x = x1, y = y1;
			for (;y < y2; y++, n++)
				result[n] = matrix[x][y];
			for (; x < x2; x++, n++)
				result[n] = matrix[x][y];
			for (; y > y1; y--, n++)
				result[n] = matrix[x][y];
			for (; x > x1; x--, n++)
				result[n] = matrix[x][y];
			x1++; y1++;
			x2--; y2--;
		}

		if (x1 == x2)
			for (x = x1, y = y1; y <= y2; y++, n++)
				result[n] = matrix[x][y];
		else if (y1 == y2)
			for (x = x1, y = y1; x <= x2; x++, n++)
				result[n] = matrix[x][y];

		return result;
	}
};