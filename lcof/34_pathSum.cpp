#include <iostream>
#include <vector>
#include <list>

using namespace std;
 
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> vv;
		if (root == NULL) return vv;
		list<int> l;
		pathSum(root, vv, l, sum);

		return vv;
	}

	void pathSum(TreeNode* node, vector<vector<int>>& vv, list<int>& l, int sum)
	{
		if (node == NULL) return;
		bool left = (node->left != NULL);
		bool right = (node->right != NULL);
		l.push_back(node->val);
		if (node->val == sum && !left && !right)
			vv.push_back(vector<int>(l.begin(), l.end()));
		else
		{
			if (left) pathSum(node->left, vv, l, sum - node->val);
			if (right) pathSum(node->right, vv, l, sum - node->val);
		}
		l.pop_back();
	}
};