#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string result;
		stack<string> s;
		char str[64];
		int len = 0;
		path = path + '/';
		for (int i = 0; i < path.size(); i++)
		{
			if (path[i] == '/' && len != 0)
			{
				if (str[len - 1] == '/')
					continue;
				else
				{
					str[len] = '\0';
					if (strcmp(str, "/..") == 0)
					{
						if (!s.empty())
							s.pop();
					}
					else if (strcmp(str, "/.") == 1)
						s.push(str);
					len = 0;
				}
			}
			str[len] = path[i];
			len++;
		}

		if (s.empty())
			result = "/";
		while (!s.empty())
		{
			result = s.top() + result;
			s.pop();
		}

		return result;
	}
};