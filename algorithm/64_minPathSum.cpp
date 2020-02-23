#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;

		int height = grid.size();
		int width = grid[0].size();

		vector<int> v(width);
		v[0] = grid[0][0];
		for (int i = 1; i < width; i++)
			v[i] = grid[0][i] + v[i - 1];

		for (int x = 1; x < height; x++)
		{
			v[0] = v[0] + grid[x][0];
			for (int y = 1; y < width; y++)
			{
				int min = v[y - 1] < v[y] ? v[y - 1] : v[y];
				v[y] = min + grid[x][y];
			}
		}

		return v[width - 1];
	}
};