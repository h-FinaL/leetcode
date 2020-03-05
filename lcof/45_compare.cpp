#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int compare(int num1, int num2)
{
    if (num2 == 0) return 0;
    if (num1 == 0) return 1;
    long n1 = num1, n2 = num2;
    int num = num2;
    while (num > 0)
    {
        num = num / 10;
        n1 = n1 * 10;
    }
    n1 = n1 + num2;
    num = num1;
    while (num > 0)
    {
        num = num / 10;
        n2 = n2 * 10;
    }
    n2 = n2 + num1;

    return n1 < n2;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        stringstream result;
        for (int i = 0; i < nums.size(); i++)
            result << to_string(nums[i]);
        return result.str();
    }
};
