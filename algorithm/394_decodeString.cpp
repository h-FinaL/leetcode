#include <iostream>
#include <stack>
#include <memory>
#include <sstream>

/*
394. 字符串解码

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<int> num_stack;
		stack<shared_ptr<stringstream>> str_stack;
		str_stack.push(shared_ptr<stringstream>(new stringstream()));
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				char num[16];
				int len = 0;
				while ('0' <= s[i] && s[i] <= '9')
					num[len++] = s[i++];
				num[len] = 0;
				num_stack.push(atoi(num));
			}
			if (s[i] == '[')
			{
				str_stack.push(shared_ptr<stringstream>(new stringstream()));
			}
			else if (s[i] == ']')
			{
				int n = num_stack.top();
				num_stack.pop();
				auto str_ptr = str_stack.top();
				str_stack.pop();
				for (int i = 0; i < n; i++)
					*str_stack.top() << str_ptr->str();
			}
			else
			{
				*str_stack.top() << s[i];
			}
		}

		return str_stack.top()->str();
	}

	//第二次完成
	string decodeString1(string s) {
		stack<int> num_stack;
		stack<stringstream> ss_stack;
		ss_stack.push(stringstream());
		char num_s[16] = { 0 };
		int len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				len = 0;
				while ('0' <= s[i] && s[i] <= '9') { num_s[len++] = s[i++]; }
				num_s[len] = 0;
				num_stack.push(atoi(num_s));
			}
			if (s[i] == '[')
			{
				ss_stack.push(stringstream());
			}
			else if (s[i] == ']')
			{
				//stringstream的str()每次都创建一个string
				//直接使用str()存在大量的内存拷贝
				string str = ss_stack.top().str();
				ss_stack.pop();
				for (int j = 0; j < num_stack.top(); j++)
					ss_stack.top() << str;
				num_stack.pop();
			}
			else
			{
				ss_stack.top() << s[i];
			}
		}

		return ss_stack.top().str();
	}

};