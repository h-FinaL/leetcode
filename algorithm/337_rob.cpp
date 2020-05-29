#include <iostream>
#include <vector>
#include <algorithm>

/*
337. 打家劫舍 III
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

*/

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		int dp1 = 0;
		int dp2 = 0;
		traverse(root, &dp1, &dp2);
		return max(dp1, dp2);
	}

	void traverse(TreeNode* node, int* dp1, int* dp2)
	{
		if (node == nullptr)
			return;

		int left_dp1 = 0;
		int left_dp2 = 0;
		int right_dp1 = 0;
		int right_dp2 = 0;
		traverse(node->left, &left_dp1, &left_dp2);
		traverse(node->right, &right_dp1, &right_dp2);
		*dp1 = left_dp2 + right_dp2 + node->val;
		*dp2 = max(left_dp1, left_dp2) + max(right_dp1, right_dp2);
	}
};