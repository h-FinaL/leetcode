#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int result = 0;
		if (height.size() < 3) 
			return result;

		int left = 0;
		int right = height.size() - 1;
		for (; left < height.size() - 1; left++)
			if (height[left + 1] < height[left]) break;
		for (; right > 0; right--)
			if (height[right - 1] < height[right]) break;
		while (left < right)
		{
			int h;
			if (height[left] <= height[right])
			{
				h = height[left];
				do
				{
					result = result + h - height[left];
					left++;
				} while (left < right && height[left] <= h);
			}
			else
			{
				h = height[right];
				do
				{
					result = result + h - height[right];
					right--;
				} while (left < right && height[right] <= h);
			}
		}

		return result;
	}
};