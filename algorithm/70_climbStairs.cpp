#include <iostream>

/*
70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

*/

using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		if (n < 3)
			return n;
		int n1 = 1;
		int n2 = 2;
		for (int i = 3; i <= n; i++)
		{
			int temp = n1;
			n1 = n2;
			n2 = temp + n2;
		}

		return n2;
	}
};