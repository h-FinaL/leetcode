#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode result(0);
		result.next = head;
		ListNode* swapNode1;
		ListNode* swapNode2;
		ListNode* node = &result;
		while (node != NULL)
		{
			if (node->next != NULL) 
				swapNode1 = node->next;
			else break;
			if (swapNode1->next != NULL) 
				swapNode2 = swapNode1->next;
			else break;
			swapNode1->next = swapNode2->next;
			swapNode2->next = swapNode1;
			node->next = swapNode2;
			node = swapNode1;
		}

		return result.next;
	}
};
