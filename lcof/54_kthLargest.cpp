#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int kthLargest(TreeNode* root, int k) {
		TreeNode* result = NULL;
		traversal(root, k, &result);

		return result ? result->val : 0;
	}

	void traversal(TreeNode* node, int& k, TreeNode** result)
	{
		if (node == 0 || k <= 0) return;
		traversal(node->right, k, result);
		k = k - 1;
		if (k == 0) 
			*result = node;
		traversal(node->left, k, result);

	}
};