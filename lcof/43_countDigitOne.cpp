#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int countr = 0;
        for (long i = 1; i <= n; i *= 10) {
            long divider = i * 10;
            countr += (n / divider) * i + min(max(n % divider - i + 1, 0L), i);
        }
        return countr;
    }
};