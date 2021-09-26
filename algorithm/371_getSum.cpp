

/*
371. 两整数之和
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

注意加上unsigned int, 否则在leetcode提交中会报溢出的错误
*/

class Solution {
public:
    int getSum(int a, int b) {
		int carry = (unsigned int)(a & b) << 1;
		int sum = a ^ b;

		while (carry != 0)
		{
			int temp = sum;
			sum = temp ^ carry;
			carry = (unsigned int)(temp & carry) << 1;
		}

		return sum;
	}
};