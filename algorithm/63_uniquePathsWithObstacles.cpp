#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
			return 0;

		int height = obstacleGrid.size();
		int width = obstacleGrid[0].size();

		vector<long> v(width, 0);
		for (int i = 0; i < width; i++)
		{
			if (obstacleGrid[0][i] != 1)
				v[i] = 1;
			else
				break;
		}

		for (int x = 1; x < height; x++)
		{
			if (obstacleGrid[x][0] == 1)
				v[0] = 0;

			for (int y = 1; y < width; y++)
			{
				if (obstacleGrid[x][y] == 1)
					v[y] = 0;
				else
					v[y] = v[y - 1] + v[y];
			}
		}

		return v[width - 1];
	}
};