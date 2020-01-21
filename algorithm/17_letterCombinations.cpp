#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> number = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ns;
		vector<string> result;
		if (digits.size() == 0) return result;
		char* s = new char[digits.size() + 1];
		for (int i = 0; i < digits.size(); i++)
		{
			ns.push_back(number[digits[i] - 50]);
		}
		fun(ns, result, s, 0);
		return result;
	}

	void fun(vector<string>& ns, vector<string>& result, char* s, int n)
	{
		for (int i = 0; i < ns[n].size(); i++)
		{
			s[n] = ns[n][i];
			if (n >= ns.size() - 1)
			{
				s[n + 1] = 0;
				result.push_back(string(s));
			}
			else
				fun(ns, result, s, n + 1);
		}
	}
};