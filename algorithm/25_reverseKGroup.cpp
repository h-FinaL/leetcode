#include <iostream>

/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
*/

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	//第2次完成
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode result(0);
        result.next = head;
        ListNode* k_pre_node = &result;
        ListNode* k_head_node = head;
        while (k_head_node != NULL)
        {
            ListNode* node = k_head_node;
            for (int i = 0; node != NULL && i < k - 1; i++)
                node = node->next;
            if (node == NULL)
                break;
            ListNode* pre_node = k_head_node;
            ListNode* last_node = k_head_node->next;
            for (int i = 0; i < k - 1; i++)
            {
                ListNode* temp_node = last_node->next;
                last_node->next = pre_node;
                pre_node = last_node;
                last_node = temp_node;
            }
            k_pre_node->next = pre_node;
            k_head_node->next = last_node;
            k_pre_node = k_head_node;
            k_head_node = last_node;
        }

        return result.next;
    }

	//第1次完成
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
