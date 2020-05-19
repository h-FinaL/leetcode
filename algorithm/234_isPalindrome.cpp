#include <iostream>

/*
234. 回文链表
请判断一个链表是否为回文链表。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
using namespace std;

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL)
			return true;
		ListNode* pre_node = NULL;
		ListNode* curr_node = head;
		while (curr_node != NULL)
		{
			if (two_lsit_is_palindrome(pre_node, curr_node) || 
				two_lsit_is_palindrome(pre_node, curr_node->next))
				return true;
			ListNode* temp = curr_node;
			curr_node = curr_node->next;
			temp->next = pre_node;
			pre_node = temp;
		}

		return false;
	}

	bool two_lsit_is_palindrome(ListNode* list1, ListNode* list2)
	{
		while (list1 && list2 && list1->val == list2->val)
		{
			list1 = list1->next;
			list2 = list2->next;
		}
		if (!list1 && !list2)
			return true;
		return false;
	}
};