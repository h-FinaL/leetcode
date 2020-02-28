#include <iostream>
#include <string>

using namespace std;
 
class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}

	bool isMatch(const char* s,const char* p)
	{
		if (*p == 0)
			return *s == 0;
		int eq = (*s != 0) && (*p == '.' ||  *p == *s);
		if (p[1] == '*')
			return (eq && isMatch(s + 1, p)) || isMatch(s, p + 2);
		else
			return eq && isMatch(s + 1, p + 1);
	}
};