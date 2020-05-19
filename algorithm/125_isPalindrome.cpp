#include <iostream>
#include <string>

/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
*/

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			while (left < right && !check(s[left]))
				left++;
			while (left < right && !check(s[right]))
				right--;
			if (tolower(s[left]) != tolower(s[right]))
				break;
			left++;
			right--;
		}
		if (left >= right)
			return true;
		return false;
	}

	bool check(char c)
	{
		if (('0' <= c && c <= '9') ||
			('a' <= c && c <= 'z') ||
			('A' <= c && c <= 'Z'))
			return true;
		return false;
	}
};