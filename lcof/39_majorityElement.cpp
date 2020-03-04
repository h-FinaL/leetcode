#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int i = 0;
        for (; i < nums.size(); i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > nums.size() / 2)
                break;
        }

        return nums[i];
    }
};