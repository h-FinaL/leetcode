#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;

		int x = matrix.size() - 1, y = 0;
		while (x >= 0 && y < matrix[0].size())
		{
			if (matrix[x][y] == target)
				return true;
			else if (matrix[x][y] > target)
				x--;
			else
				y++;
		}
		return false;
	}
};
