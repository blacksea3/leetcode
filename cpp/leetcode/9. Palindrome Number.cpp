#include "public.h"

//8ms 99.79%

//技巧,当前反转数字值 > 去除一位数字的数字值 表示不为回文数   ,  此回文数为奇数长度
//当前反转数字值 == 去除一位数字的数字值 表示为回文数         ,  此回文数为奇数长度
//当前反转数字值 == 未去除一位数字的数字值 表示不为回文数     ,  此回文数为偶数长度
//当前反转数字值 == 未去除一位数字的数字值 表示为回文数       ,  此回文数为偶数长度

//边界情况:对个位数单独处理

class Solution {
public:
	bool isPalindrome(int x) {
		//边界情况
		if (x < 0) return false;
		if (x < 10) return true;
		if (x % 10 == 0) return false;

		int reverse = 0;
		int temp = 0;
		int nextx = 0;

		while (true)
		{
			nextx = x / 10;
			temp = reverse * 10 + x % 10;
			if (reverse > nextx) return false;
			else if (reverse == nextx) return true;
			else
			{
				if (temp > nextx) return false;
				else if (temp == nextx) return true;
				else
				{
					reverse = temp;
					x = nextx;
				}
			}
		}
		return false;   //dump, code will not arrive here
	}
};
