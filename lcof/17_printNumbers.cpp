#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
	vector<int> printNumbers(int n) {
		int num = pow(10, n) - 1;
		vector<int> v(num);
		for (int i = 0; i < num; i++)
			v[i] = i + 1;

		return v;
	}
};