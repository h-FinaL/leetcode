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
	vector<int> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		levelOrder(root, vv, 0);
		vector<int> result;
		for (int i = 0; i < vv.size(); i++)
			result.insert(result.end(), vv[i].begin(), vv[i].end());

		return result;
	}

	void levelOrder(TreeNode* root, vector<vector<int>>& vv, int n)
	{
		if (root == NULL) return;
		if (n >= vv.size()) vv.push_back(vector<int>());
		vv[n].push_back(root->val);
		levelOrder(root->left, vv, n + 1);
		levelOrder(root->right, vv, n + 1);
	}
};