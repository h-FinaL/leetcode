#include <iostream>
#include <vector>

/*
501. 二叉搜索树中的众数

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        int max_len = 1, len = 0, val = 0;
        mid_sequence(root, &val, &len, &max_len, res);

        return res;
    }

    void mid_sequence(TreeNode* root, int* val, int* len, int* max_len, vector<int>& res)
    {
        if (root == nullptr)
            return;
        mid_sequence(root->left, val, len, max_len, res);
        if (root->val != *val)
        {
            *len = 1;
            *val = root->val;
        }
        else
        {
            *len += 1;
        }

        if (*len > *max_len)
        {
            *max_len = *len;
            res.clear();
            res.push_back(*val);
        }
        else if (*len == *max_len)
        {
            res.push_back(*val);
        }
        mid_sequence(root->right, val, len, max_len, res);
    }
};