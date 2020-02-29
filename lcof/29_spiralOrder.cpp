#include <iostream>
#include <vector>

using namespace std;

 
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return vector<int>();

		int x1 = 0, y1 = 0;
		int x2 = matrix.size() - 1, y2 = matrix[0].size() - 1;
		vector<int> result(matrix.size() * matrix[0].size());

		int i = 0;
		int x, y;
		while (x1 < x2 && y1 < y2)
		{
			x = x1, y = y1;
			for (; y < y2; y++, i++)
				result[i] = matrix[x][y];
			for (; x < x2; x++, i++)
				result[i] = matrix[x][y];
			for (; y > y1; y--, i++)
				result[i] = matrix[x][y];
			for (; x > x1; x--, i++)
				result[i] = matrix[x][y];
			x1++; y1++;
			x2--; y2--;
		}
		x = x1, y = y1;
		if (x1 == x2) while (y <= y2) { result[i] = matrix[x][y], y++, i++; }
		else if (y1 == y2) while (x <= x2) { result[i] = matrix[x][y], x++, i++; }

		return result;
	}
};