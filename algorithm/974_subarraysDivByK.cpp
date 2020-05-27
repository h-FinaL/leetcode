#include <iostream>
#include <vector>
#include <unordered_map>

/*
974. 和可被 K 整除的子数组
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
*/

using namespace std;

class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		int result = 0;
		unordered_map<int, int> m;
		int n = 0;
		for (int i = 0; i < A.size(); i++)
		{
			n = ((n + A[i]) % K + K) % K;
			m[n]++;
		}
		for (auto& i : m)
		{
			result += (i.second - 1) * i.second / 2;
		}
		result += m[0];

		return result;
	}
};