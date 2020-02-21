#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> v;
		if (candidates.empty()) return result;

		sort(candidates.begin(), candidates.end());
		combination(candidates, target, result, v,0, 0);

		return result;
	}

	void combination(vector<int>& candidates, int target, vector<vector<int>>& vv, vector<int>& v, int i, int n)
	{
		if (n >= v.size())
			v.push_back(0);
		while (i < candidates.size() && candidates[i] <= target)
		{
			v[n] = candidates[i];
			if (target == candidates[i])
			{
				vv.push_back(vector<int>(v.begin(), v.begin() + n + 1));
				return;
			}
			combination(candidates, target - candidates[i], vv, v, i, n + 1);
			i++;
		}
	}
};