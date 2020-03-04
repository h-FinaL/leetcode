#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        if (arr.empty() || k == 0) return result;

        priority_queue<int> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};