#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        long len = 0;
        long t = 1;
        for (; len + t * 9 * i < n; t *= 10)
        {
            len = len + t * 9 * i;
            i++;
        }
        long num = (n - len - 1) / i + t;
        int index = (n - len - 1) % i;
        for (int j = index; j < i - 1; j++)
            num = num / 10;

        return num % 10;
    }
};