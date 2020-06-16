#include <iostream>
#include <sstream>
#include <queue>

/*
297. 二叉树的序列化与反序列化
*/

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		stringstream ss;
		ss << '[';
		if (root == nullptr)
		{
			ss << ']';
			return ss.str();
		}
		queue<TreeNode*> que;
		que.push(root);
		int null_size = 0;
		while (!que.empty() && null_size != que.size())
		{
			int n = que.size();
			null_size = 0;
			for (int i = 0; i < n; i++)
			{
				TreeNode* node = que.front();
				if (node != nullptr)
				{
					ss << node->val << ',';
					que.push(node->left);
					que.push(node->right);
					if (node->left == nullptr)
						null_size++;
					if (node->right == nullptr)
						null_size++;
				}
				else
				{
					ss << "null,";
				}
				que.pop();
			}
		}
		
		string res = ss.str();
		res[res.size() - 1] = ']';
		return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		queue<string> que;
		queue<TreeNode*> node_que;
		TreeNode* res = nullptr;
		char num_str[16];
		for (int i = 1; i < data.size() - 1; i++)
		{
			int len = 0;
			while (data[i] != ',' && data[i] != ']')
			{
				num_str[len++] = data[i++];
			}
			num_str[len] = 0;
			que.push(num_str);
		}
		int n = 0;
		if (!que.empty() && que.front() != "null")
		{
			res = new TreeNode(atoi(que.front().c_str()));
			node_que.push(res);
			que.pop();
			n = 1;
		}
		while (!node_que.empty() && !que.empty())
		{
			TreeNode* node = node_que.front();
			if (que.front() != "null")
			{
				node->left = new TreeNode(atoi(que.front().c_str()));
				node_que.push(node->left);
			}
			que.pop();
			if (que.empty())
				break;
			if (que.front() != "null")
			{
				node->right = new TreeNode(atoi(que.front().c_str()));
				node_que.push(node->right);
			}
			que.pop();
			node_que.pop();
		}

		return res;
    }
};