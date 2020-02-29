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
	TreeNode* mirrorTree(TreeNode* root) {
		mirrorTreeF(root);
		return root;
	}

	void mirrorTreeF(TreeNode* root)
	{
		if (root != NULL)
		{
			TreeNode* node = root->left;
			root->left = root->right;
			root->right = node;
			mirrorTreeF(root->left);
			mirrorTreeF(root->right);
		}
	}
};