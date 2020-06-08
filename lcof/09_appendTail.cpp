#include <iostream>
#include <stack>

using namespace std;
 
/*
面试题09. 用两个栈实现队列
*/

class CQueue{
public:
	CQueue() {

	}

	void appendTail(int value) {
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(value);
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	int deleteHead() {
		if (s1.empty())
			return -1;
		int result = s1.top();
		s1.pop();
		return result;
	}
private:
	stack<int> s1;
	stack<int> s2;
};

//第二次实现
class CQueue1 {
public:
	CQueue() {

	}

	void appendTail(int value) {
		s1.push(value);
	}

	int deleteHead() {
		int res = -1;
		if (!s2.empty())
		{
			res = s2.top();
			s2.pop();
		}
		else
		{
			while (s1.size() > 1)
			{
				s2.push(s1.top());
				s1.pop();
			}
			if (s1.size() == 1)
			{
				res = s1.top();
				s1.pop();
			}
		}
		return res;
	}
private:
	stack<int> s1;
	stack<int> s2;
}; 