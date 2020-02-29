#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		return verifyPostorder(postorder, 0, postorder.size() - 1);
	}

	bool verifyPostorder(vector<int>& postorder, int start, int end)
	{
		if (start >= end) return true;
		int left = start;
		while (left < end && postorder[left] < postorder[end])
			left++;
		int right = left;
		while (right < end && postorder[right] > postorder[end])
			right++;
		if (right < end) return false;

		return verifyPostorder(postorder, start, left - 1) && verifyPostorder(postorder, left, end - 1);
	}
};