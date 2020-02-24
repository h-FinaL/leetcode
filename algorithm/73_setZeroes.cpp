#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int oneColZero = 0, oneRowZero = 0;

		for (int x = 0; x < matrix.size(); x++)
			if (matrix[x][0] == 0)
			{
				oneColZero = 1;
				break;
			}
		for(int y = 0; y < matrix[0].size(); y++)
			if (matrix[0][y] == 0)
			{
				oneRowZero = 1;
				break;
			}


		for (int x = 1; x < matrix.size(); x++)
		{
			for (int y = 1; y < matrix[0].size(); y++)
			{
				if (matrix[x][y] == 0)
				{
					matrix[x][0] = 0;
					matrix[0][y] = 0;
				}
			}
		}

		for (int x = 1; x < matrix.size(); x++)
		{
			if (matrix[x][0] == 0)
			{
				for (int y = 1; y < matrix[0].size(); y++)
				{
					matrix[x][y] = 0;
				}
			}
		}

		for (int y = 1; y < matrix[0].size(); y++)
		{
			if (matrix[0][y] == 0)
			{
				for (int x = 1; x < matrix.size(); x++)
				{
					matrix[x][y] = 0;
				}
			}
		}

		if (oneColZero)
			for (int x = 0; x < matrix.size(); x++)
				matrix[x][0] = 0;
		if (oneRowZero)
			for (int y = 0; y < matrix[0].size(); y++)
				matrix[0][y] = 0;
	}
};