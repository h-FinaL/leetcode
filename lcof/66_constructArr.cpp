#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> result;
		if (a.empty())
			return result;
		vector<int> v(a.size(), 0);
		v[a.size() - 1] = a[a.size() - 1];
		for (int i = a.size() - 2; i > 0; i--)
			v[i] = v[i + 1] * a[i];

		result.push_back(v[1]);
		v[0] = a[0];
		for (int i = 1; i < a.size() - 1; i++)
		{
			result.push_back(v[i - 1] * v[i + 1]);
			v[i] = a[i] * v[i - 1];
		}
		result.push_back(v[a.size() - 2]);

		return result;
	}
};