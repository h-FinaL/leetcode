#include <iostream>
#include <deque>

/*
402. 移掉K位数字
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
*/

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (num.size() <= k)
			return "0";
		deque<char> deq;
		deq.push_back('0');
		for (auto& c : num)
		{
			while (k > 0 && deq.back() > c)
			{
				deq.pop_back();
				k--;
			}
			deq.push_back(c);
		}

		auto begin = deq.begin();
		auto end = deq.end() - k;
		while (*begin == '0')
			begin++;

		if (begin == end) return "0";
		return string(begin, end);
	}
};