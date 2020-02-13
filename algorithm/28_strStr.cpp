#include <iostream>
#include <string>
#include <vector>

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
};