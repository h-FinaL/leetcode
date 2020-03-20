#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		if (k == 0) return result;
		deque<int> deq;
		for (int i = 0; i < nums.size(); i++)
		{
			while (!deq.empty() && nums[i] > nums[deq.back()])
				deq.pop_back();
			if (!deq.empty() && i - k == deq.front())
				deq.pop_front();
			deq.push_back(i);
			if (i >= k - 1)
				result.push_back(nums[deq.front()]);
		}

		return result;
	}
};