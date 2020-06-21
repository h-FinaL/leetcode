#include <iostream>
#include <algorithm>

/*
124. 二叉树中的最大路径和
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int n_max = INT32_MIN;
        maxPathSum(root, &n_max);
        return n_max;
    }

    int maxPathSum(TreeNode* node, int* n_max)
    {
        int res;
        int n_right;
        int n_left;
        if (!node->left && !node->right)
        {
            res = node->val;
        }
        else if (!node->left)
        {
            n_right = maxPathSum(node->right, n_max);
            res = max(node->val, n_right + node->val);
        }
        else if (!node->right)
        {
            n_left = maxPathSum(node->left, n_max);
            res = max(node->val, n_left + node->val);
        }
        else
        {
            n_left = maxPathSum(node->left, n_max);
            n_right = maxPathSum(node->right, n_max);
            *n_max = max(*n_max, node->val + n_left + n_right);
            res = max(node->val, max(n_left + node->val, n_right + node->val));
        }
        
        *n_max = max(res, *n_max);
        return res;
    }
};