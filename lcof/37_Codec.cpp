#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL) return "[]";
        stringstream result;
        result << "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
            {
                result << "null,";
            }
            else
            {
                result << std::to_string(node->val) << ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        result << "]";
        return result.str();
    }

    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        int i = 0;
        while (i < data.size() && data[i] != '[') { i++; }
        i++;
        char s[5];
        int j = 0;
        while (i < data.size() && data[i] != ',' && data[i] != ']')
        {
            s[j] = data[i];
            j++;
            i++;
        }
        s[j] = 0;

        TreeNode* head = new TreeNode(std::atoi(s));
        queue<TreeNode*> q;
        q.push(head);
        i++;
        j = 0;
        while (i < data.size())
        {
            TreeNode* node = q.front();
            q.pop();
            for (int k = 0; k < 2; k++)
            {
                while (i < data.size() && data[i] != ',' && data[i] != ']')
                {
                    s[j] = data[i];
                    j++;
                    i++;
                }
                s[j] = 0;
                i++;
                j = 0;
                if (strcmp(s, "null") != 0)
                {
                    TreeNode* sonNode = new TreeNode(std::atoi(s));
                    if (k == 0)
                        node->left = sonNode;
                    else
                        node->right = sonNode;
                    q.push(sonNode);
                }
            }
        }

        return head;
    }

};