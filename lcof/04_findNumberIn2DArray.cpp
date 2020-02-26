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

	//二分查找
	bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;

		int left = 0, right = matrix.size();
		int x, y;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == 0)
			return false;
		else
			x = left - 1;
		left = 0;
		right = matrix[0].size();
		while (left < right)
		{
			mid = (left + right) / 2;
			if (matrix[x][mid] == target)
				return true;
			else if (matrix[x][mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == 0)
			return false;
		else
			y = left;
		left = 0;
		right = x;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (matrix[mid][y] == target)
				return true;
			else if (matrix[mid][y] < target)
				left = mid + 1;
			else
				right = mid;
		}

		return false;
	}
};
