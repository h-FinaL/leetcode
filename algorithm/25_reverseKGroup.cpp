#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1) return head;

		ListNode result(0);
		result.next = head;
		ListNode* right = &result;
		ListNode* left = right;

		while (right != NULL)
		{
			left = right;
			for (int i = 0; i < k && right != NULL; i++)
				right = right->next;
			if (right == NULL) break;

			ListNode* swap1 = left;
			ListNode* swap2 = left->next;
			left = swap2->next;
			swap1->next = right;
			swap2->next = right->next;
			right = swap2; 

			for (int i = 0; i < k - 1; i++)
			{
				swap1 = swap2;
				swap2 = left;
				left = left->next;
				swap2->next = swap1;
			}
		}

		return result.next;
	}
};
