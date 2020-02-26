#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		if (s.empty()) return "";

		vector<char> v(s.size() * 3 + 1);
		int len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				v[len] = '%';
				v[len + 1] = '2';
				v[len + 2] = '0';
				len = len + 3;
			}
			else
			{
				v[len] = s[i];
				len++;
			}
		}
		v[len] = 0;

		return string(&v[0]);
	}
};