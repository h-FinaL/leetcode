#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0 || strs[0].size() == 0 )
			return "";
		if (strs.size() == 1)
			return strs[0];

		char* p = new char[strs[0].size() + 1];
		for (int i = 0; i < strs[0].size(); i++)
		{
			for (int j = 1; j < strs.size(); j++)
			{
				if (strs[j][i] != strs[0][i])
				{
					p[i] = 0;
					string s(p);
					delete p;
					return s;
				}
			}
			p[i] = strs[0][i];
		}
		p[strs[0].size()] = 0;
		string s(p);
		delete p;
		return s;

	}
};