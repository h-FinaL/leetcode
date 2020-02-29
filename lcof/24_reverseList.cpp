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
	ListNode* reverseList(ListNode* head) {
		ListNode* result = NULL;
		ListNode* pre;
		while (head != NULL)
		{
			pre = head;
			head = head->next;
			pre->next = result;
			result = pre;
		}

		return result;
	}
};