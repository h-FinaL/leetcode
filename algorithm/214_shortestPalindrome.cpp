#include <iostream>
#include <string>
#include <vector>
 
/*
214. 最短回文串
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。
找到并返回可以用这种方式转换的最短回文串
*/

using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		int n = s.size();
		string rev(s);
		reverse(rev.begin(), rev.end());
		string s_new = s + "#" + rev;
		int n_new = s_new.size();
		vector<int> f(n_new, 0);
		for (int i = 1; i < n_new; i++) {
			int t = f[i - 1];
			while (t > 0 && s_new[i] != s_new[t])
				t = f[t - 1];
			if (s_new[i] == s_new[t])
				++t;
			f[i] = t;
		}
		return rev.substr(0, n - f[n_new - 1]) + s;
	}

	//自己实现的时间复杂度要高
	//但测试后所花的时间却要低
	string shortestPalindrome1(string s) {
		string rev(s);
		reverse(rev.begin(), rev.end());
		int len = 0;
		int j = 0;
		for (int i = 0; i < rev.size(); i++)
		{
			while (j + len <= i)
			{
				if (s[len] == rev[j + len])
					len++;
				else
				{
					len = 0;
					j++;
				}
			}
		}

		return rev.substr(0, s.size() - len) + s;
	}
};