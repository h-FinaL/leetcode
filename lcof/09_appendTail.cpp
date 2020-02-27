#include <iostream>
#include <stack>

using namespace std;
 
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