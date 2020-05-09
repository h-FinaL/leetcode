#include <iostream>
#include <stack>

/*
331. 验证二叉树的前序序列化
*/

using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<char> stk;
		stk.push(0);
		int i = 0;
		char word[16];
		while (i < preorder.size() && !stk.empty())
		{
			int len = 0;
			while ('0' <= preorder[i] && preorder[i] <= '9' || preorder[i] == '#')
			{
				word[len] = preorder[i];
				len++;
				i++;
			}
			if (word[0] == '#')
				stk.pop();
			else
				stk.push(1);

			while (i < preorder.size() && !('0' <= preorder[i] && preorder[i] <= '9' || preorder[i] == '#'))
				i++;
		}

		if (i == preorder.size() && stk.empty())
			return true;
		return false;
	}
};