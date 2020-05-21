#include <iostream>

/*
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

using namespace std;

class Solution {
public:
	//第二次实现
	string longestPalindrome2(string s) {
		if (s.empty())
			return "";
		int max_len = 0;
		int max_p = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int right = i + j;
				int left = i - 1;
				int len = j;
				while (right < s.size() && left >= 0 && s[right] == s[left])
				{
					right++;
					left--;
					len += 2;
				}
				if (len > max_len)
				{
					max_len = len;
					max_p = i;
				}
			}
		}

		return s.substr(max_p - max_len / 2, max_len);
	}
	//第一次实现
	string longestPalindrome(string s) {
		const char* str = s.c_str();
		int len = s.length();
		int maxsize = 0;
		int maxposition = 0;
		for (int i = 0; i < len; i++)
		{
			int size = even(str, len, i);
			if (size > maxsize)
			{
				maxsize = size;
				maxposition = i;
			}
			size = odd(str, len, i);
			if (size > maxsize)
			{
				maxsize = size;
				maxposition = i;
			}
		}
		if (maxsize != 0)
		{
			int start = maxposition - (maxsize + 1) / 2 + 1;
			return s.substr(start, maxsize);
		}
		return string();
	}
	int even(const char* str, int len, int position)
	{
		int size = 0;
		int left = position;
		int right = position + 1;
		while (left >= 0 && right < len)
		{
			if (str[left] == str[right])
			{
				size = size + 2;
				left--;
				right++;
			}
			else
				break;
		}
		return size;
	}

	int odd(const char* str, int len, int position)
	{
		int size = 1;
		int left = position - 1;
		int right = position + 1;
		while (left >= 0 && right < len)
		{
			if (str[left] == str[right])
			{
				size = size + 2;
				left--;
				right++;
			}
			else
				break;
		}
		return size;
	}

};