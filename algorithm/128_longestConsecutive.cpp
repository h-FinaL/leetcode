#include <iostream>
#include <vector>
#include <unordered_map>

/*
128. 最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
*/

using namespace std;
class Solution {
public:
    //在连续区间里，区间的最大值存储当前区间的长度，区间的他值value置为0
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int res = 1;
        unordered_map<int, int> m;
        //去重并初始化长度为1
        for (auto& n : nums)
        {
            m[n] = 1;
        }
        for (auto& n : m)
        {
            //为0说明在连续区间中,跳过避免重复计算
            if (n.second == 0)
                continue;
            int next = n.first - 1;
            //查找下一个数并累计长度
            while (m.find(next) != m.end() && m[next] >= 1)
            {
                n.second += m[next];
                //区间内的数置为0
                m[next] = 0;
                next--;
            }
            res = n.second > res ? n.second : res;
        }
        return res;
    }
};