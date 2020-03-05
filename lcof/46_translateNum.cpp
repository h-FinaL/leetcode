#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        vector<int> n;
        while (num > 0)
        {
            n.push_back(num % 10);
            num = num / 10;
        }
        return translateNum(n, n.size() - 1);
    }

    int translateNum(vector<int>& n, int i)
    {
        if (i < 1) return 1;
        int n1 = n[i];
        int n2 = n1 * 10 + n[i - 1];
        if (n1 > 0 && n2 < 26)
            return translateNum(n, i - 1) + translateNum(n, i - 2);
        else
            return translateNum(n, i - 1);
    }
};