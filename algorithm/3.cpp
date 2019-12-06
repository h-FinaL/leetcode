#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const char* c = s.c_str();
		std::map<char, int> m;
		int maxlen = 0;
		int first = 0;
		int last = 0;
		for (int i = 0; i <= s.length(); i++)
		{
			if (m.find(c[i]) == m.end())
			{
				m[c[i]] = i;
			}
			else
			{
				if (i - first > maxlen)
					maxlen = i - first;
				last = m[c[i]] + 1;
				for (int j = first; j <= m[c[i]]; j++)
				{
					m.erase(c[j]);
				}
				m[c[i]] = i;
				first = last;
			}
		}

		if (s.length() - first > maxlen)
			maxlen = s.length() - first;

		return maxlen;
	}
};