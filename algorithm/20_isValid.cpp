#include <iostream>
#include <string>
#include <stack>

using namespace std;
 
class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0) return true;
		stack<char> stack;
		const char* str = s.c_str();
		char c;
		for (int i = 0; i < s.size() ; i++)
		{
			if (str[i] == '{')
				stack.push('}');
			else if (str[i] == '[')
				stack.push(']');
			else if (str[i] == '(')
				stack.push(')');
			else
			{
				if (stack.empty() || stack.top() != str[i])
					return false;
				if (str[i] == stack.top())
					stack.pop();
			}
		}
		return stack.empty();
	}
};