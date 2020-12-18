#include <string>

/*
389. 找不同
给定两个字符串 s 和 t，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。
*/

using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        char letter[26] = { 0 };
        for (auto c : s)
        {
            letter[c - 'a']++;
        }

        for (auto c : t)
        {
            if (letter[c - 'a'] == 0)
                res = c - 'a';
            else
                letter[c - 'a']--;
        }

        return res;
    }
};