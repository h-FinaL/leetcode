#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() < 2)
			return;
		
		int size = matrix.size();
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = i; j < size - i - 1; j++)
			{
				int swap = matrix[i][j];
				matrix[i][j] = matrix[size - j - 1][i];
				matrix[size -j - 1][i] = matrix[size - i - 1][size - j - 1];
				matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];
				matrix[j][size - i - 1] = swap;
			}
		}
	}
};