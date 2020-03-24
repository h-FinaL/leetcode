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
		if (root == NULL)
			return NULL;
		TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
		TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
		if (root == p) return p;
		if (root == q) return q;
		if (node1 != NULL && node2 != NULL) return root;
		else if (node1 == NULL && node2 == NULL) return NULL;
		else if (node1 != NULL) return node1;
		else return node2;
	}
};