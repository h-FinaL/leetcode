#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int>& v1, vector<int>& v2)
{
	if (v1[0] < v2[0])
		return 1;
	return 0;
}

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) 
			return intervals;

		sort(intervals.begin(), intervals.end(), compare);
		vector<int> v(2);
		v[0] = intervals[0][0];
		v[1] = intervals[0][1];
		vector<vector<int>> result;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (v[1] < intervals[i][0])
			{
				result.push_back(v);
				v[0] = intervals[i][0];
				v[1] = intervals[i][1];
			}
			else
				v[1] = intervals[i][1] > v[1] ? intervals[i][1] : v[1];

			if (i == intervals.size() - 1)
				result.push_back(v);
		}

		return result;
	}
};