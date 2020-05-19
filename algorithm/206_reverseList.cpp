#include <iostream>

/*
206. 反转链表
反转一个单链表。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
using namespace std;

class Solution {
public:
	// 迭代实现
	ListNode* reverseList(ListNode* head) {
		ListNode* pre_node = nullptr;
		ListNode* node = head;
		while (node)
		{
			ListNode* temp = node;
			node = node->next;
			temp->next = pre_node;
			pre_node = temp;
		}

		return pre_node;
	}

	// 递归实现
	ListNode* reverseList_(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* node = reverseList_(head->next);
		head->next->next = head;
		head->next = nullptr;
		return node;
	}
};