#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> result;
		while (head != NULL)
		{
			result.push_back(head->val);
			head = head->next;
		}
		int left = 0, right = result.size() - 1;
		while (left < right)
		{
			swap(result[left], result[right]);
			left++;
			right--;
		}

		return result;
	}
};