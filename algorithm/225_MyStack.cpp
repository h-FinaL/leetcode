#include <iostream>
#include <queue>

/*
225. 用队列实现栈
*/

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() : 
		m_que(new queue<int>()), 
		m_que_as(new queue<int>())
	{}

	~MyStack()
	{
		delete m_que;
		delete m_que_as;
	}

	/** Push element x onto stack. */
	void push(int x) {
		m_que->push(x);
		m_top = x;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (m_que->empty())
			throw "stack is empty!";

		while (m_que->size() > 1)
		{
			if (m_que->size() == 2)
				m_top = m_que->front();
			m_que_as->push(m_que->front());
			m_que->pop();
		}

		int result = m_que->front();
		m_que->pop();
		swap(m_que, m_que_as);
		return result;
	}

	/** Get the top element. */
	int top() {
		if (m_que->empty())
			throw "stack is empty!";
		else
			return m_top;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return m_que->empty();
	}

private:
	queue<int>* m_que;
	queue<int>* m_que_as;
	int m_top;
};