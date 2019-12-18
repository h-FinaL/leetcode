#include <iostream>

using namespace std;

class Solution {
public:
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