#include "public.h"

//12ms, 98.28%

//朴素的解法
//按每一位进行操作

class Solution {
public:
	string stringMultiple(char c, int num)
	{
		string returnstring = "";
		while (num > 0)
		{
			returnstring += c;
			num--;
		}
		return returnstring;
	}

	string intToRoman(int num)
	{
		//按顺序一个一个数字扣下来, num = [1,3999]
		int son;
		string returns;
		son = num % 10;
		if (son == 9) returns = "IX";
		else if (son == 4) returns = "IV";
		else if (son > 4) returns = "V" + stringMultiple('I', son - 5);
		else returns = stringMultiple('I', son);
		num /= 10;

		son = num % 10;
		if (num == 0) return returns;
		else if (son == 9) returns = "XC" + returns;
		else if (son == 4) returns = "XL" + returns;
		else if (son > 4) returns = "L" + stringMultiple('X', son - 5) + returns;
		else returns = stringMultiple('X', son) + returns;
		num /= 10;

		son = num % 10;
		if (num == 0) return returns;
		else if (son == 9) returns = "CM" + returns;
		else if (son == 4) returns = "CD" + returns;
		else if (son > 4) returns = "D" + stringMultiple('C', son - 5) + returns;
		else returns = stringMultiple('C', son) + returns;
		num /= 10;

		son = num % 10;
		if (num == 0) return returns;
		else return stringMultiple('M', son) + returns;
	}
};
