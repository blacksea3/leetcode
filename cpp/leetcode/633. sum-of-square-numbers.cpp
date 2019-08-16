#include "public.h"

//300ms, 5.06%
//遍历1到(int)sqrt(c), 记录数字的平方并且放入set, 如果set中已经放了,则OK
//特殊情况: c/2就是完全平方数

class Solution {
public:
	bool judgeSquareSum(int c) {
		if (c % 2 == 0 && ((int)(sqrt(c / 2))*(int)(sqrt(c / 2)) == c/2)) return true;

		unordered_set<int> memory;

		for (int i = 0; i <= (int)sqrt(c); ++i)
		{
			if (memory.find(c - i * i) == memory.end()) memory.insert(i*i);
			else return true;
		}
		return false;
	}
};
