#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return string(s);
		int len = s.length();
		char* convstr = new char[len + 1];
		convstr[len] = '\0';
		char* str = convstr;
		int n = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < (len - 1) / (2 * numRows - 2) + 1; j++)
			{
				int p1 = i + j * (2 * numRows - 2);
				int p2 = p1 + (numRows - i - 1) * 2;
				if (i == 0 && p1 < len)
				{
					*str = s[p1];
					str++;
				}
				else if (i == numRows - 1 && p1 < len)
				{
					*str = s[p1];
					str++;
				}
				else
				{
					if (p1 < len)
					{
						*str = s[p1];
						str++;
					}
					if (p2 < len)
					{
						*str = s[p2];
						str++;
					}
				}
			}
		}
		string result(convstr);
		delete []convstr;
		return result;
	}

};