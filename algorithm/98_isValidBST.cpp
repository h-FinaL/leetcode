#include <iostream>
#include <vector>

/*
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

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
	bool isValidBST(TreeNode* root) {
		vector<int> v;
		isValidBST(root, v);
		int i = 1;
		for (; i < v.size(); i++)
		{
			if (v[i] <= v[i - 1])
				break;
		}
		if (i < v.size())
			return false;

		return true;
	}

	void isValidBST(TreeNode* root, vector<int>& v)
	{
		if (root == nullptr)
			return;
		isValidBST(root->left, v);
		v.push_back(root->val);
		isValidBST(root->right, v);
	}
};