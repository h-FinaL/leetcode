#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int result = 0;
		vector<vector<int>> vv(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int x = matrix.size() - 1; x >= 0; x--)
		{
			for (int y = matrix[0].size() - 1; y >= 0; y--)
			{
				int n = 1;
				while (y >= 0 && matrix[x][y] == '1')
				{
					vv[x][y] = n;
					n++;
					y--;
				}
			}
		}
		stack<int> s;
		s.push(-1);
		for (int y = 0; y < vv[0].size(); y++)
		{
			for (int x = 0; x < vv.size(); x++)
			{
				while (s.size() > 1 && vv[s.top()][y] > vv[x][y])
				{
					int height = vv[s.top()][y];
					s.pop();
					int area = height * (x - s.top() - 1);
					result = area > result ? area : result;
				}
				s.push(x);
			}
			while (s.size() > 1)
			{
				int height = vv[s.top()][y];
				s.pop();
				int area = height * (vv.size() - s.top() - 1);
				result = area > result ? area : result;
			}
		}

		return result;
	}
};