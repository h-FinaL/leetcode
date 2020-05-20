#include <iostream>
#include <vector>
#include <algorithm>

/*
1371. 每个元音包含偶数次的最长子字符串
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：
每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
*/
 
using namespace std;

class Solution {
public:
	int findTheLongestSubstring(string s) {
		int ans = 0, status = 0, n = s.size();
		vector<int> pos(32, -1);
		pos[0] = 0;
		for (int i = 0; i < n; i++) 
		{
			if (s[i] == 'a')
				status ^= 1 << 0;
			else if (s[i] == 'e')
				status ^= 1 << 1;
			else if (s[i] == 'i')
				status ^= 1 << 2;
			else if (s[i] == 'o')
				status ^= 1 << 3;
			else if (s[i] == 'u')
				status ^= 1 << 4;
			// 如果p1到p2为偶数个
			// 0-p1的status和0-p2的status相同
			if (pos[status] != -1)
				ans = max(ans, i + 1 - pos[status]);
			else
				pos[status] = i + 1;
		}
		return ans;
	}
};