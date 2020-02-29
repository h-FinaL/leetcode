#include <iostream>
#include <queue>

using namespace std;

class MinStack {
public:
	MinStack() : stack(NULL) {

	}

	void push(int x) {
		Stack* s = new Stack(x);
		if (stack != NULL)
			s->bottom = stack;
		minq.push(x);
		stack = s;
	}

	void pop() {
		if (stack != NULL)
		{
			Stack* s = stack;
			stack = stack->bottom;
			if (s->val == minq.top())
				minq.pop();
			delete s;
		}
	}

	int top() {
		if (stack != NULL)
			return stack->val;
		return 0;
	}

	int min() {
		return minq.top();
	}
private:
	struct Stack {
		int val;
		Stack* bottom;
		Stack(int val) : val(val), bottom(NULL) {}
	};
	Stack* stack; 
	priority_queue<int, vector<int>, greater<int> > minq;
};