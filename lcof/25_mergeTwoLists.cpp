#include <iostream>

using namespace std;
 
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head = ListNode(0);
		ListNode* node = &head;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				node->next = l2;
				break;
			}
			else if (l2 == NULL)
			{
				node->next = l1;
				break;
			}
			else if (l1->val < l2->val)
			{
				node->next = l1;
				l1 = l1->next;
				node = node->next;
			}
			else
			{
				node->next = l2;
				l2 = l2->next;
				node = node->next;
			}
		}

		return head.next;
	}
};