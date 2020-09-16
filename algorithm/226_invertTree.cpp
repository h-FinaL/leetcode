#include <iostream>

/*
226. 翻转二叉树

翻转一棵二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }

    void invert(TreeNode* node)
    {
        if (node == nullptr)
            return;
        swap(node->left, node->right);
        invert(node->left);
        invert(node->right);
    }
};