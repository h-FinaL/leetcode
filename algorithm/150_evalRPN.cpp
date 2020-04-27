#include <iostream>
#include <vector>
#include <stack>

/*
150. 逆波兰表达式求值
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, /
说明：
    整数除法只保留整数部分。
    给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

*/

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> num_stack;
		for (auto& str : tokens)
			operate(num_stack, str);

		return  num_stack.top();
	}

	void operate(stack<int>& num_stack, string& str)
	{
		if ( ('0' <= str[0] && str[0] <= '9') || (str[0] == '-' && str.size() > 1) )
			num_stack.push(atoi(str.c_str()));
		else
		{
			int num1 = num_stack.top();
			num_stack.pop();
			int num2 = num_stack.top();
			num_stack.pop();
			int n;
			if (str[0] == '+')
				n = num2 + num1;
			else if (str[0] == '-')
				n = num2 - num1;
			else if (str[0] == '*')
				n = num2 * num1;
			else
				n = num2 / num1;
			num_stack.push(n);
		}
	}
};