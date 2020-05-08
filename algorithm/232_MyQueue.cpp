#include <iostream>
#include <stack>

/*
232. 用栈实现队列
*/

using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (!m_stack2.empty())
			move_stack(m_stack2, m_stack1);
		m_stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (m_stack1.empty() && m_stack2.empty())
			throw "queue is empty!";

		if (!m_stack1.empty())
			move_stack(m_stack1, m_stack2);

		int result = m_stack2.top();
		m_stack2.pop();
		return result;
	}

	/** Get the front element. */
	int peek() {
		if (m_stack1.empty() && m_stack2.empty())
			throw "queue is empty!";

		if (!m_stack1.empty())
			move_stack(m_stack1, m_stack2);

		return m_stack2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (m_stack1.empty() && m_stack2.empty());
	}


private:
	void move_stack(stack<int>& stack1, stack<int>& stack2)
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	stack<int> m_stack1;
	stack<int> m_stack2;
};
