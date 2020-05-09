#include <iostream>
#include <stack>

/*
224. 基本计算器
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
*/

using namespace std;

class Solution {
public:
#define LEFT_BRACKET 0
#define RIGHT_BRACKET 1
#define ADD_SIGN 2
#define SUB_SIGN 3
	int calculate(string s) {
		stack<int> num_stack;
		stack<int> sign_stack;
		num_stack.push(0);
		sign_stack.push(ADD_SIGN);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
				continue;
			if (s[i] == '+')
				sign_stack.push(ADD_SIGN);
			else if (s[i] == '-')
				sign_stack.push(SUB_SIGN);
			else if (s[i] == '(')
				sign_stack.push(LEFT_BRACKET);
			else if (s[i] == ')')
			{
				if (sign_stack.top() != LEFT_BRACKET)
					throw "Wrong expression!";
				sign_stack.pop();
				int sign = sign_stack.top();
				sign_stack.pop();
				int num1 = num_stack.top();
				num_stack.pop();
				int num2 = num_stack.top();
				num_stack.pop();
				num_stack.push(calc(num2, num1, sign));
			}
			else if('0' <= s[i] && s[i] <= '9')
			{
				int len = 0;
				char word[16];
				while ('0' <= s[i] && s[i] <= '9')
					word[len++] = s[i++];
				word[len] = 0;
				int num1 = atoi(word);
				if (sign_stack.top() == LEFT_BRACKET)
					num_stack.push(num1);
				else
				{
					int num2 = num_stack.top();
					num_stack.pop();
					int sign = sign_stack.top();
					sign_stack.pop();
					num_stack.push(calc(num2, num1, sign));
				}
				i--;
			}
		}

		return num_stack.top();
	}
private:
	int calc(int num1, int num2, int sign)
	{
		if (sign == ADD_SIGN)
			return num1 + num2;
		if (sign == SUB_SIGN)
			return num1 - num2;
		return 0;
	}
};