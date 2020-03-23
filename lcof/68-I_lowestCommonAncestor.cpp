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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* maxNode = p->val > q->val ? p : q;
		TreeNode* minNode = p->val <= q->val ? p : q;
		if (minNode->val <= root->val && root->val <= maxNode->val)
			return root;
		else if (root->val < minNode->val)
			return lowestCommonAncestor(root->right, p, q);
		else 
			return lowestCommonAncestor(root->left, p, q);
	}

};