#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) == m.end())
                m[s[i]] = i;
            else
                m[s[i]] = -1;
        }
        auto i = m.begin();
        while (i != m.end() && i->second == -1) { i++; }
        if (i == m.end()) 
            return ' ';

        int min = i->second;
        i++;
        while (i != m.end())
        {
            if (i->second != -1)
                min = i->second < min ? i->second : min;
            i++;
        }

        return s[min];
    }
};