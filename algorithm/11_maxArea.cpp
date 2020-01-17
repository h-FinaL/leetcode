#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int left = 0;
		int right = height.size() - 1;
		int m_height;
		int length;
		while (left < right)
		{
			m_height = height[left] < height[right] ? height[left] : height[right];
			length = right - left;
			if (height[left] < height[right])
			{
				m_height = height[left];
				left++;
			}
			else
			{
				m_height = height[right];
				right--;
			}
			if (max < m_height * length)
				max = m_height * length;
		}
		return max; 
	}
};