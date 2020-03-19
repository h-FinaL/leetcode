#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string result;
		int len = 0;
		int i = s.size() - 1;
		while (i >= 0)
		{
			if (s[i] != ' ')
				len++;
			else if (s[i] == ' ' && len > 0)
			{
				result = result + s.substr(i + 1, len) + " ";
				len = 0;
			}
			--i;
		}
		if (len > 0)
			result = result + s.substr(0, len);
		else
			result = result.substr(0, result.size() - 1);

		return result;
	}
};