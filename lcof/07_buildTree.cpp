#include <iostream>
#include <string>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return NULL;
		TreeNode* head = new TreeNode(0);
		build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, head);

		return head;
	}

	void build(vector<int>& preorder, int pStart, int pEnd,
		vector<int>& inorder, int iStart, int iEnd,
		TreeNode* t)
	{
		t->val = preorder[pStart];

		int leftLen = 0;
		for (; leftLen + iStart <= iEnd; leftLen++)
			if (inorder[leftLen + iStart] == preorder[pStart])
				break;
		if (leftLen > iEnd)
			leftLen = 0;

		if (leftLen > 0)
		{
			t->left = new TreeNode(0);
			build(preorder, pStart + 1, pStart + leftLen, inorder, iStart, iStart + leftLen - 1, t->left);
		}
		if (pStart + leftLen < pEnd)
		{
			t->right = new TreeNode(0);
			build(preorder, pStart + leftLen + 1, pEnd, inorder, iStart + leftLen + 1, iEnd, t->right);
		}
	}
};

int main()
{
	Solution s;
	vector<int> v1{ 3 , 9, 20, 15, 7 };
	vector<int> v2{9, 3, 15, 20, 7};
	s.buildTree(v1, v2);

	return 0;
}