#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int pre = 0;
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{

			if (m[s[i]] > pre)
			{
				result = result + m[s[i]] - 2 * pre;
			}
			else
				result = result + m[s[i]];
			pre = m[s[i]];
		}
		return result;
	}

};