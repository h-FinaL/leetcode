#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.empty()) 
			return 0;
		int left = 0;
		int right = numbers.size() - 1;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (numbers[mid] > numbers[right])
				left = mid + 1;
			else if (numbers[mid] < numbers[left])
				right = mid;
			else
				right--;
		}

		return numbers[left];
	}
};