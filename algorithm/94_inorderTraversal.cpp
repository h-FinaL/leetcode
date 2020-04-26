#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;

		stack<TreeNode*> stack_tree_node;
		TreeNode* node = root;
		while (node != NULL || !stack_tree_node.empty())
		{
			while (node != NULL)
			{
				stack_tree_node.push(node);
				node = node->left;
			}

			node = stack_tree_node.top();
			stack_tree_node.pop();
			result.push_back(node->val);
			node = node->right;
		}

		return result;
	}

	//第一次做的
	vector<int> inorderTraversal_(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;

		stack<TreeNode*> stack_tree_node;
		stack_tree_node.push(root);
		while (!stack_tree_node.empty())
		{
			TreeNode* parent = stack_tree_node.top();
			if (parent->right)
			{
				stack_tree_node.pop();
				stack_tree_node.push(parent->right);
				stack_tree_node.push(parent);
			}
			//用来标记上一个是父节点
			stack_tree_node.push(NULL);
			if (parent->left)
			{
				stack_tree_node.push(parent->left);
			}

			if (stack_tree_node.top() && !stack_tree_node.top()->left && !stack_tree_node.top()->right)
			{
				result.push_back(stack_tree_node.top()->val);
				stack_tree_node.pop();
			}
			if (!stack_tree_node.empty() && stack_tree_node.top() == NULL)
			{
				stack_tree_node.pop();
				result.push_back(stack_tree_node.top()->val);
				stack_tree_node.pop();
			}
		}

		return result;
	}



};