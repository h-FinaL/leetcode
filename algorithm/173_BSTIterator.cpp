#include <iostream>
#include <stack>

/*
173. 二叉搜索树迭代器
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
调用 next() 将返回二叉搜索树中的下一个最小的数。
*/

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		TreeNode* node = root;
		while (node)
		{
			m_node_stack.push(node);
			node = node->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = m_node_stack.top();
		int result = node->val;
		node = node->right;
		m_node_stack.pop();
		while (node)
		{
			m_node_stack.push(node);
			node = node->left;
		}
		return result;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!m_node_stack.empty())
			return true;
		return false;
	}
private:
	stack<TreeNode*> m_node_stack;
};