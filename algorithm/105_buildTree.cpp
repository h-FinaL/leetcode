#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;
		TreeNode* node = buildTree(preorder, 0, inorder, 0, preorder.size());
		return node;
	}

	TreeNode* buildTree(vector<int>& preorder, int pstart,
		vector<int>& inorder, int istart, int len)
	{
		if (len == 1) return new TreeNode(preorder[pstart]);
		int leftLen = 0;
		TreeNode* node = new TreeNode(preorder[pstart]);
		while (!(inorder[istart + leftLen] == node->val))
			leftLen++;
		if (leftLen >= 1)
			node->left = buildTree(preorder, pstart + 1, inorder, istart, leftLen);
		if (len - leftLen - 1 >= 1)
			node->right = buildTree(preorder, pstart + leftLen + 1, inorder, istart + leftLen + 1, len - leftLen - 1);
		return node;
	}
};