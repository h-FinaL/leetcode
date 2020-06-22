#include <iostream>

/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。
*/

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int len = max(a.size(), b.size()) + 2;
        char* str = (char*)malloc(sizeof(char) * len);
        str[len - 1] = 0;
        int i = len - 2;
        int ia = a.size() - 1;
        int ib = b.size() - 1;
        int flag = 0;
        while (i >= 0)
        {
            int n = flag;
            if (ia >= 0)
                n += a[ia] - '0';
            if (ib >= 0)
                n += b[ib] - '0';
            if (n < 2)
            {
                str[i] = n + '0';
                flag = 0;
            }
            else
            {
                str[i] = n - 2 + '0';
                flag = 1;
            }
            i--; ia--; ib--;
        }
        if (str[0] == '0')
            res = string(str + 1);
        else
            res = string(str);
        free(str);
        return res;
    }
};