#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;

		int x = 0;
		int y = 0;
		int xHei = 0, xLow = matrix.size();
		int yleft = 0, yRight = matrix[0].size();
		while (xHei <  xLow)
		{
			x = (xHei + xLow) / 2;
			if (matrix[x][0] == target)
				return true;
			else if (matrix[x][0] < target)
				xHei = x + 1;
			else
				xLow = x;
		}
		x = xHei - 1;
		if (x < 0)
			return false;

		while (yleft < yRight)
		{
			y = (yleft + yRight) / 2;
			if (matrix[x][y] == target)
				return true;
			else if (matrix[x][y] < target)
				yleft = y + 1;
			else
				yRight = y;
		}

 		return false;
	}
};