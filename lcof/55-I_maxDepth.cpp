#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int maxDepth(TreeNode* root) {
		return maxDepth(root, 1);
	}

	int maxDepth(TreeNode* node, int depth)
	{
		if (node == NULL) return depth - 1;
		return max(maxDepth(node->left, depth + 1), maxDepth(node->right, depth + 1));
	}
};