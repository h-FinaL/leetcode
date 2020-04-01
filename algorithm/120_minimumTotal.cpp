#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		if (triangle.size() == 1) return triangle[0][0];
		vector<int> v(triangle.size(), 0);
		v[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++)
		{
			v[i] = v[i - 1] + triangle[i][i];
			for (int j = i - 1; j > 0; j--)
			{
				int min = v[j] < v[j - 1] ? v[j] : v[j - 1];
				v[j] = min + triangle[i][j];
			}
			v[0] = v[0] + triangle[i][0];
		}
		int result = v[0];
		for (int i = 0; i < v.size(); i++)
			result = v[i] < result ? v[i] : result;
		return result;
	}
};