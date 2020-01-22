#include <iostream>


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n == 0) return head;
		ListNode* h = head;
		ListNode* p = head;
		ListNode* l;
		for (int i = 0; i < n; i++)
			h = h->next;
		if (h == NULL)
		{
			l = head;
			head = head->next;
		}
		else 
		{
			while (h->next != NULL)
			{
				h = h->next;
				p = p->next;
			}
			l = p->next;
			p->next = p->next->next;
		}
		delete l;
		return head;
	}
};