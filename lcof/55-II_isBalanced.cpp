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
	bool isBalanced(TreeNode* root) {
		if (isBalanced(root, 0) == -1)
			return false;
		else
			return true;
	}

	int isBalanced(TreeNode* node, int depth)
	{
		if (node == NULL) return depth;
		int left = isBalanced(node->left, depth + 1);
		int right = isBalanced(node->right, depth + 1);
		if (-1 <= left - right && left - right <= 1)
			return left > right ? left : right;
		else
			return -1;
	}
};
