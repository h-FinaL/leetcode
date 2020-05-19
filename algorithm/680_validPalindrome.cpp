#include <iostream>
#include <string>

/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			if (s[left] != s[right])
				break;
			left++;
			right--;
		}
		if (left >= right)
			return true;
		return validPalindrome(s, left + 1, right) || validPalindrome(s, left, right - 1);
	}

	bool validPalindrome(string& s, int left, int right)
	{
		while (left < right)
		{
			if (s[left] != s[right])
				break;
			left++;
			right--;
		}
		if (left >= right)
			return true;
		return false;
	}
};