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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return equal(root->left, root->right);
	}

	bool equal(TreeNode* t1, TreeNode* t2)
	{
		if (t1 == NULL && t2 == NULL) 
			return true;
		if (t1 == NULL || t2 == NULL || t1->val != t2->val)
			return false;
		return equal(t1->left, t2->right) && equal(t1->right, t2->left);
	}
};