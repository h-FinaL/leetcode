#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) return head;
		Node* node = head;
		while (node != NULL)
		{
			Node* n = new Node(node->val);
			n->next = node->next;
			node->next = n;
			node = node->next->next;
		}
		node = head;
		while (node != NULL)
		{
			if (node->random == NULL)
				node->next->random = NULL;
			else
				node->next->random = node->random->next;
			node = node->next->next;
		}

		node = head;
		Node result(0);
		Node* r = &result;
		while (node != NULL)
		{
			r->next = node->next;
			node->next = node->next->next;
			r = r->next;
			node = node->next;
		}

		return result.next;
	}

	//使用map
	Node* copyRandomList1(Node* head) {
		Node* node = head;
		unordered_map<Node*, Node*> m;
		while (node != NULL)
		{
			m[node] = new Node(node->val);
			node = node->next;
		}
		node = head;
		while (node != NULL)
		{
			m[node]->next = m[node->next];
			m[node]->random = m[node->random];
			node = node->next;
		}

		return m[head];
	}
};