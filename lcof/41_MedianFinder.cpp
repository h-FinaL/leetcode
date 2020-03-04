#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (left.empty())
            left.push(num);
        else if (left.size() == right.size())
        {
            if (num > -right.top())
            {
                left.push(-right.top());
                right.pop();
                right.push(-num);
            }
            else
                left.push(num);
        }
        else if(num < left.top())
        {
            right.push(-left.top());
            left.pop();
            left.push(num);
        }
        else
            right.push(-num);
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + (-right.top())) / 2.0;
        else
            return left.top();
    }

    priority_queue<int> left;
    priority_queue<int> right;
};