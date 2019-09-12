#include "public.h"

//0ms, 100%
//有限状态机

class Solution {
public:
	bool isNumber(string s) {
		//去除开头的空格
		int slen = s.size();
		if (slen == 0) return false;
		int loc = 0;


		while (s[loc] == ' ')
		{
			if (loc == slen - 1) return false;  //全是空格
			loc++;
		}

		//去掉末尾空格
		int last = slen - 1;
		while (s[last] == ' ') last--;

		int state = 0;   //0:等待数字或符号或者小数点, 1:(有了符号)等待一个数字或者小数点, 2:已有有效数字/符号组合
		//等待可能的小数点/'e'或者其他数字(或者遍历结束),
		//3:已有小数点,等待e或者其他数字(或者遍历结束, 4:已有e,等待其他数字或者符号,(遍历不能直接结束)
		//5:已有e以及符号,等待其他数字,(遍历不能直接结束)
		//6:已有e,等待其他数字(或者遍历结束)

		bool no_number_before_point = false;   //如果小数点前面没有数字,要是后面也没有数字则返回false
		loc -= 1;

		//注意这里有些技巧,我给loc先减了1,则特别需要注意for的循环次数
		for (int i = loc; i < last; i++)
		{
			loc++;
			switch (state)
			{
			case 0:
			{
				if ((s[loc] == '+') || (s[loc] == '-')) state = 1;
				else if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
				else if (s[loc] == '.')
				{
					state = 3;
					no_number_before_point = true;
				}
				else return false;
				break;
			}
			case 1:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
				else if (s[loc] == '.')
				{
					state = 3;
					no_number_before_point = true;
				}
				else return false;
				break;
			}
			case 2:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0'));
				else if (s[loc] == '.') state = 3;
				else if (s[loc] == 'e') state = 4;
				else return false;
				break;
			}
			case 3:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) no_number_before_point = false;
				else if (s[loc] == 'e')
				{
					if (no_number_before_point) return false;
					state = 4;
				}
				else return false;
				break;
			}
			case 4:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
				else if ((s[loc] == '+') || (s[loc] == '-')) state = 5;
				else return false;
				break;
			}
			case 5:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
				else return false;
				break;
			}
			case 6:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0'));
				else return false;
				break;
			}
			}
		}

		switch (state)
		{
		case 0:
		case 1:
		case 4:
		case 5:
			return false;
		case 2:
		case 6:
			return true;
		case 3:
			return !(no_number_before_point);
		default:
			return false;
		}
	}
};