#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

int compare(ListNode* node1, ListNode* node2)
{
	if (node1 == NULL) return 1;
	if (node2 == NULL) return 0;
	return (node1->val < node2->val);
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head(0);
		ListNode* node = &head;

		list<ListNode*> sortList;

		sort(lists.begin(), lists.end(), compare);
		int i = 0;
		for (auto i = lists.begin(); i != lists.end(); i++)
			if (*i != NULL)
				sortList.push_back(*i);

		ListNode* min;
		while (1)
		{
			if (sortList.empty()) break;
			min = sortList.front();
			node->next = min;
			min = min->next;
			node = node->next;

			sortList.pop_front();
			if (sortList.empty())
			{
				node = min;
				break;
			}
			if (min != NULL)
			{
				auto i = sortList.begin();
				while (i != sortList.end())
					if (min->val <= (*i)->val) break;
					else i++;
				sortList.insert(i, min);
			}
		}

		return head.next;
	}
};
