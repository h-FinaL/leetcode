#include <iostream>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int n = 1;
		string s;
		while (num > 0)
		{
			n = n * 10;
			s = getString(num % 10, n) + s;
			num = num / 10;
		}
		return s;
	}
	string getString(int num, int n)
	{
		string s;
		switch (n)
		{
		case 10:
			s = getStr(num, 'I', 'V', 'X');
			break;
		case 100:
			s = getStr(num, 'X', 'L', 'C');
			break;
		case 1000:
			s = getStr(num, 'C', 'D', 'M');
			break;
		case 10000:
			s = getStr(num, 'M', '\0', '\0');
			break;
		}
		return s;
	}
	string getStr(int num, char x, char y, char z)
	{
		string str;
		switch (num)
		{
		case 9:
			str = str + x + z;
			break;
		case 8:
			str = str + y + x + x + x;
			break;
		case 7:
			str = str + y + x + x;
			break;
		case 6:
			str = str + y + x;
			break;
		case 5:
			str = str + y;
			break;
		case 4:
			str = str + x + y;
			break;
		case 3:
			str = str + x;
		case 2:
			str = str + x;
		case 1:
			str = str + x;
			break;
		}
		return str;
	}
};