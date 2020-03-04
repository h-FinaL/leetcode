#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        if (s.size() == 0) return vector<string>();
        vector<string> result;
        //set<string> setStr;
        //permutation(s, 0, setStr);
        //for (auto i = setStr.begin(); i != setStr.end(); i++)
        //    result.push_back(*i);
        permutation(s, 0, result);

        return result;
    }

    //利用排序避免重复
    void permutation(string s, int n, vector<string>& result)
    {
        if (n >= s.size())
            result.push_back(s);
        else
        {
            sort(s.begin() + n, s.end());
            int i = n;
            while ( i < s.size())
            {
                swap(s[i], s[n]);
                permutation(s, n + 1, result);
                swap(s[i], s[n]);
                do { i++; } while (i < s.size() && s[i] == s[i - 1]);
            }
        }
    }

    //利用set去重
    void permutation(string& s, int n, set<string>& setStr)
    {
        if (n >= s.size())
            setStr.insert(s);
        else
        {
            for (int i = n; i < s.size(); i++)
            {
                swap(s[n], s[i]);
                permutation(s, n + 1, setStr);
                swap(s[n], s[i]);
            }
        }
    }
};