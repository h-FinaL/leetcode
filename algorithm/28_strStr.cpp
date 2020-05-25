#include <iostream>
#include <string>
#include <vector>

/*
28. 实现 strStr()
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。
*/

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.size() < needle.size()) return -1;
		int n = haystack.size() - needle.size();

		vector<int> v(needle.size());
		v[0] = -1;
		if (needle.size() > 1) v[1] = 0;
		int maxLen = 0;
		int k = 1;
		for (int i = 2; i < needle.size(); i++)
		{
			do
			{
				if (needle[maxLen] == needle[k + maxLen])
					maxLen++;
				else
				{
					maxLen = 0;
					k++;
				}
			} while (k + maxLen < i);
			v[i] = maxLen;
		}
		
		int needleTag = 0;
		int haystackTag = 0;
		while (haystackTag - needleTag <= n && needleTag < needle.size())
		{
			if (haystack[haystackTag] != needle[needleTag])
				if (needleTag == 0) haystackTag++;
				else needleTag = v[needleTag];
			else
			{
				needleTag++;
				haystackTag++;
			}
		}

		if (needleTag >= needle.size())
			return haystackTag - needle.size();
		return -1;
	}

	//第二次完成
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.size() < needle.size()) return -1;

		vector<int> v(needle.size(), 0);
		for (int i = 1; i < needle.size(); i++)
		{
			int len = v[i - 1];
			while (len > 0 && needle[len] != needle[i])
				len = v[len - 1];
			if (needle[len] == needle[i])
				len++;
			v[i] = len;
		}

		int haystack_i = 0;
		int needle_i = 0;
		int diff_len = haystack.size() - needle.size();
		while (haystack_i <= diff_len + needle_i && needle_i < needle.size())
		{
			if (needle[needle_i] == haystack[haystack_i])
			{
				haystack_i++;
				needle_i++;
			}
			else
			{
				if (needle_i == 0)
					haystack_i++;
				else
					needle_i = v[needle_i - 1];
			}
		}
		if (needle_i >= needle.size())
			return haystack_i - needle_i;
		return -1;
	}
};