#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;

        Node head;
        Node* pre = &head;
        Node* last;
        treeToDoublyList(root, &pre, &last);
        last->right = head.right;
        head.right->left = last;

        return head.right;
	}

    void treeToDoublyList(Node* node, Node** pre, Node** last)
    {
        if (node == NULL) return;
        treeToDoublyList(node->left, pre, last);
        (*pre)->right = node;
        node->left = *pre;
        *pre = (*pre)->right;
        *last = node;
        treeToDoublyList(node->right, pre, last);
    }
};