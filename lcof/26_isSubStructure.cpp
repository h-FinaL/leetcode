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
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (B == NULL) return false;
		return traversal(A, B);
	}

	bool traversal(TreeNode* a, TreeNode* b)
	{
		if (a == NULL) return false;
		if (equal(a, b)) return true;
		return traversal(a->left, b) || traversal(a->right, b);
	}

	bool equal(TreeNode* a, TreeNode* b)
	{
		if (b == NULL)
			return true;
		if (a == NULL || a->val != b->val)
			return false;

		return equal(a->left, b->left) && equal(a->right, b->right);
	}
};