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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* node1 = l1;
		ListNode* node2 = l2;
		int num1 = 0;
		int num2 = 0;
		int num = 0;
		int isin = 0;
		ListNode* list = new ListNode(0);
		ListNode* node = list;
		while ((node1 != NULL || node2 != NULL) || isin == 1)
		{
			if (node1 != NULL)
			{
				num1 = node1->val;
				node1 = node1->next;
			}
			else
				num1 = 0;

			if (node2 != NULL)
			{
				num2 = node2->val;
				node2 = node2->next;
			}
			else
				num2 = 0;
			num = num1 + num2;

			if (isin == 1)
				num = num + 1;

			if (num >= 10)
			{
				num = num % 10;
				isin = 1;
			}
			else
			{
				isin = 0;
			}

			node->next = new ListNode(num);
			node = node->next;
		}

		node = list;
		list = list->next;
		delete node;
		return list;
	}
};