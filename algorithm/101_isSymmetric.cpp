#include <iostream>
#include <stack>

/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
*/

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) 
            return true;
        return isSymmetric(root->left, root->right);
    }
    //递归实现
    bool isSymmetric(TreeNode* sym_left, TreeNode* sym_right)
    {
        if (sym_left == nullptr && sym_right == nullptr)
            return true;
        if (sym_left == nullptr || sym_right == nullptr || sym_left->val != sym_right->val)
            return false;
        return isSymmetric(sym_left->left, sym_right->right) && 
                isSymmetric(sym_left->right, sym_right->left);
    }
    //迭代实现
    bool isSymmetric_(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty())
        {
            TreeNode* sym_node1 = stk.top();
            stk.pop();
            TreeNode* sym_node2 = stk.top();
            stk.pop();
            if (sym_node1 == nullptr && sym_node2 == nullptr)
                continue;
            if (sym_node1 == nullptr || sym_node2 == nullptr || sym_node1->val != sym_node2->val)
                return false;
            stk.push(sym_node1->right);
            stk.push(sym_node2->left);
            stk.push(sym_node1->left);
            stk.push(sym_node2->right);
        }

        return true;
    }
};