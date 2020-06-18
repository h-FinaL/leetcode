#include <iostream>
#include <stack>

/*
1028. 从先序遍历还原二叉树
我们从二叉树的根节点 root 开始进行深度优先搜索。
在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。
如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
如果节点只有一个子节点，那么保证该子节点为左子节点。
给出遍历输出 S，还原树并返回其根节点 root。

*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public:
	TreeNode* recoverFromPreorder(string S) {
		TreeNode res(0);
		stack<TreeNode*> stk;
		stk.push(&res);
		char num[16];
		int len = 0;
		int dep = 0;
		int i = 0;
		while (i < S.size())
		{
			while (dep < stk.size() - 1)
			{
				stk.pop();
			}
			len = 0;
			while ('0' <= S[i] && S[i] <= '9')
			{
				num[len] = S[i];
				i++;
				len++;
			}
			num[len] = 0;
			TreeNode** node = &(!stk.top()->left ? stk.top()->left : stk.top()->right);
			*node = new TreeNode(atoi(num));
			stk.push(*node);
			dep = 0;
			while (S[i] == '-')
			{
				i++;
				dep++;
			}
		}

		return res.left;
	}

};