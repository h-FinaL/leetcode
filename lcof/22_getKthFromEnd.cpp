#include <iostream>

using namespace std;
 
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == NULL) return head;
		ListNode* start = head;
		ListNode* end = head;
		int i = 0;
		while (i < k && end != NULL)
		{
			end = end->next;
			i++;
		}
		if (i < k) return head;
		while (end != NULL)
		{
			start = start->next;
			end = end->next;
		}

		return start;
	}
};