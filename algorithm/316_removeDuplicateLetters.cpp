#include <iostream>
#include <deque>
#include <sstream>

/*
316. 去除重复字母
给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。
需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
*/

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		deque<char> deq;
		char word[26] = { 0 };
		char exist[26] = { 0 };
		for (auto& c : s)
			word[c - 'a']++;

		for (auto& c : s)
		{
			if (exist[c - 'a'])
			{
				word[c - 'a']--;
				continue;
			}

			while (!deq.empty() && c < deq.back() && word[deq.back() - 'a'])
			{
				exist[deq.back() - 'a'] = 0;
				deq.pop_back();
			}
			deq.push_back(c);
			word[c - 'a']--;
			exist[c - 'a'] = 1;
		}

		stringstream ss;
		for (int i = deq.size() - 1; i >= 0; i--)
		{
			ss << deq.front();
			deq.pop_front();
		}

		return ss.str();
	}
};