#include <iostream>
#include <stack>
#include <queue>

/*
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

*/

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		m_stack.push(x);
		if (m_min_stack.empty())
			m_min_stack.push(x);
		else
		{
			if (x > m_min_stack.top())
				m_min_stack.push(m_min_stack.top());
			else
				m_min_stack.push(x);
		}
	}

	void pop() {
		if (!m_stack.empty())
		{
			m_stack.pop();
			m_min_stack.pop();
		}
	}

	int top() {
		if (!m_stack.empty())
			return m_stack.top();
		else
			throw "stack is empty!";
	}

	int getMin() {
		if (!m_min_stack.empty())
			return m_min_stack.top();
		else
			throw "stack is empty!";
	}
private:
	stack<int> m_stack;
	stack<int> m_min_stack;
};