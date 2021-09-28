/*
437. 路径总和 III
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

*/



#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {

        if (root == nullptr)
            return 0;

        std::vector<int> v;
        return pathSum(root, targetSum, v, 0);
    }

    int pathSum(TreeNode* node, int targetSum, std::vector<int>& sums, int depth)
    {
        int path_num = 0;

        if (sums.size() <= depth)
            sums.push_back(0);

        for (int i = 0; i < depth + 1; i++)
        {
            sums[i] = sums[i] + node->val;
            if (sums[i] == targetSum)
                path_num++;
        }

        if (node->left != nullptr)
            path_num += pathSum(node->left, targetSum, sums, depth + 1);
        if (node->right != nullptr)
            path_num += pathSum(node->right, targetSum, sums, depth + 1);


        for (int i = 0; i < depth + 1; i++)
        {
            sums[i] = sums[i] - node->val;
        }

        return path_num;
    }
};