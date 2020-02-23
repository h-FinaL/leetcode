#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (intervals.empty())
			return vector<vector<int>>{newInterval};

		auto start = intervals.end();
		auto i = intervals.begin();
		for (; i != intervals.end(); i++)
		{
			if (start == intervals.end())
			{
				if (newInterval[1] < (*i)[0])
				{
					intervals.insert(i, newInterval);
					break;
				}
				else if (newInterval[0] > (*i)[1])
					continue;
				else
				{
					(*i)[0] = (*i)[0] < newInterval[0] ? (*i)[0] : newInterval[0];
					start = i;
				}
			}
			else 
			{
				if (newInterval[1] < (*i)[0])
				{
					(*start)[1] = (*(i - 1))[1] > newInterval[1] ? (*(i - 1))[1] : newInterval[1];
					intervals.erase(start + 1, i);
					i = intervals.begin();
					break;
				}
			}
		}

		if (i == intervals.end())
		{
			if (start != intervals.end())
			{
				(*start)[1] = (*(i - 1))[1] > newInterval[1] ? (*(i - 1))[1] : newInterval[1];
				intervals.erase(start + 1, i);
			}
			else
				intervals.push_back(newInterval);
		}

		return intervals;
	}
};