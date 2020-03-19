#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> result;
		deque<int> d;

		int i = 1;
		int sum = 0;
		while (i <= target / 2 + 2)
		{
			if (sum < target)
			{
				sum = sum + i;
				d.push_back(i);
				i++;
			}
			else if (sum >= target)
			{
				if (sum == target && d.size() > 1)
					result.push_back(vector<int>(d.begin(), d.end()));
				sum = sum - d.front();
				d.pop_front();
			}
		}

		return result;
	}
};