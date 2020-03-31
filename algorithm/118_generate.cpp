#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows <= 0) 
			return result;
		vector<int> v{ 1 };
		result.push_back(v);
		for (int i = 1; i < numRows; i++)
		{
			v.push_back(1);
			for (int j = 1; j < i; j++)
				v[j] = result[i - 1][j - 1] + result[i - 1][j];
			result.push_back(v);
		}

		return result;
	}
};