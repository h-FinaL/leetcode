#include <iostream>
#include <vector>

using namespace std;

/*
106. 从中序与后序遍历序列构造二叉树
*/

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

/*
20200925
*/
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build_node(inorder.data(), inorder.size(), postorder.data(), postorder.size());
        return root;
    }

    TreeNode* build_node(int* inorder, int inorder_len, int* postorder, int postorder_len)
    {
        if (inorder_len == 0 || postorder == 0)
            return nullptr;
        TreeNode* node = new TreeNode(postorder[postorder_len - 1]);
        int left_len = 0;
        while (node->val != inorder[left_len]) { left_len++; }
        node->left = build_node(inorder, left_len, postorder, left_len);
        node->right = build_node(inorder + left_len + 1, inorder_len - left_len - 1, postorder + left_len, postorder_len - left_len - 1);
        return node;
    }
};