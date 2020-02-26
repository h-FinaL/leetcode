#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		
		stack<int> s;
		s.push(-1);
		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			while (s.top() != -1 && heights[i] <= heights[s.top()])
			{
				int height = heights[s.top()];
				s.pop();
				int area = height * (i - s.top() - 1);
				maxArea = area > maxArea ? area : maxArea;
			}
			s.push(i);
		}

		while (s.top() != -1)
		{
			int height = heights[s.top()];
			s.pop();
			int area = height * (heights.size() - s.top() - 1);
			maxArea = area > maxArea ? area : maxArea;
		}

		return maxArea;
	}
};