#include <iostream>
#include <vector>

/*
95. 不同的二叉搜索树 II
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) 
            return res;
        build_Tree(1, n, res);
        return res;
    }

    void build_Tree(int start, int end, vector<TreeNode*>& res)
    {
        if (start > end)
        {
            res.push_back(nullptr);
            return;
        }
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> v_left;
            vector<TreeNode*> v_right;
            int left_len = 0;
            int right_len = 0;
            build_Tree(start, i - 1, v_left);
            build_Tree(i + 1, end, v_right);
            for (auto& left_node : v_left)
            {
                for (auto& right_node : v_right)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = left_node;
                    node->right = right_node;
                    res.push_back(node);
                }
            }
        }
    }
};