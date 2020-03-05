#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxLen = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            while (m.find(s[right]) != m.end() && m[s[right]] != 0)
            {
                m[s[left]]--;
                left++;
            }
            if (m.find(s[right]) == m.end() || m[s[right]] == 0)
            {
                m[s[right]]++;
                right++;
                maxLen = right - left > maxLen ? right - left : maxLen;
            }
        }

        return maxLen;
    }
};