#include <iostream>
#include <vector>
#include <stack>

/*
145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> node_stack;
		TreeNode* node = root;
		while (node || !node_stack.empty())
		{
			while (node)
			{
				node_stack.push(node);
				node = node->left;
			}
			while (!node_stack.empty() && node_stack.top() == NULL)
			{
				node_stack.pop();
				result.push_back(node_stack.top()->val);
				node_stack.pop();
			}
			if (!node_stack.empty())
			{
				node = node_stack.top();
				if (node->right)
				{
					//左子树遍历完用NULL标记
					node_stack.push(NULL);
					node = node->right;
				}
				else
				{
					result.push_back(node_stack.top()->val);
					node_stack.pop();
					node = NULL;
				}
			}
		}
		return result;
	}
};
