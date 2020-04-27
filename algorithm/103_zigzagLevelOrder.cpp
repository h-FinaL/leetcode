#include <iostream>
#include <vector>
#include <stack>

/*
103. 二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> node_stack0;
		stack<TreeNode*> node_stack1;
		//1代表顺序 0代表逆序
		int seq = 1;
		node_stack1.push(root);
		while ( !(node_stack0.empty() && node_stack1.empty()) )
		{
			vector<int> v;
			if (seq == 1)
			{
				while (!node_stack1.empty())
				{
					TreeNode* node = node_stack1.top();
					node_stack1.pop();
					v.push_back(node->val);
					if (node->left)
						node_stack0.push(node->left);
					if (node->right)
						node_stack0.push(node->right);
				}
				seq = 0;
			}
			else
			{
				while (!node_stack0.empty())
				{
					TreeNode* node = node_stack0.top();
					node_stack0.pop();
					v.push_back(node->val);
					if (node->right)
						node_stack1.push(node->right);
					if (node->left)
						node_stack1.push(node->left);
				}
				seq = 1;
			}
			result.push_back(v);
		}

		return result;
	}
};
