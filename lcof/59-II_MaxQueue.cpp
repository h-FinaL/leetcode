#include <iostream>
#include <queue>
#include <deque>

using namespace std;
class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (deq.empty())
			return -1;
		return deq.front();
	}

	void push_back(int value) {
		q.push(value);
		while (!deq.empty() && deq.back() < value)
			deq.pop_back();
		deq.push_back(value);
	}

	int pop_front() {
		if (q.empty())
			return -1;

		int value = q.front();
		if (value == deq.front())
			deq.pop_front();
		q.pop();

		return value;
	}
private:
	queue<int> q;
	deque<int> deq;
};