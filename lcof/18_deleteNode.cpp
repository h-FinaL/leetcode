#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == NULL) return head;
		if (head->val == val) return head->next;
		ListNode* node = head;
		while (node->next != NULL)
		{
			if (node->next->val == val)
			{
				node->next = node->next->next;
				break;
			}
			else
				node = node->next;
		}
		return head;
	}
};