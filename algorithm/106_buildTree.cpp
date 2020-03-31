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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty())
			return NULL;
		TreeNode* node = buildTree(inorder, 0, postorder, 0, inorder.size());
		return node;
	}

	TreeNode* buildTree(vector<int>& inorder, int pstart,
		vector<int>& postorder, int istart, int len)
	{
		TreeNode* node = new TreeNode(postorder[istart + len - 1]);
		if (len == 1) return node;
		int leftLen = 0;
		while (!(inorder[pstart + leftLen] == node->val))
			leftLen++;
		if (leftLen >= 1)
			node->left = buildTree(inorder, pstart, postorder, istart, leftLen);
		if (len - leftLen - 1 >= 1)
			node->right = buildTree(inorder, pstart + leftLen + 1, postorder, istart + leftLen, len - leftLen - 1);
		return node;
	}
};