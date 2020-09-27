/*
235. 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        if ((root->val - p->val) * (root->val - q->val) <= 0)
        {
            return root;
        }
        else if (root->val > p->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return nullptr;
    }
};