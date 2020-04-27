#include <iostream>
#include <vector>
#include <stack>

/*
144. 二叉树的前序遍历
给定一个二叉树，返回它的 前序 遍历
迭代实现
*/


using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> node_stack;
		node_stack.push(root);
		while (!node_stack.empty())
		{
			TreeNode* node = node_stack.top();
			node_stack.pop();
			result.push_back(node->val);
			if (node->right)
				node_stack.push(node->right);
			if (node->left)
				node_stack.push(node->left);
		}

		return result;
	}
};
