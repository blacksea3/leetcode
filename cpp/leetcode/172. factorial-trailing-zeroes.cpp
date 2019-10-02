#include "public.h"

//0ms, 100%
//数学
//就是判断5个次数(因为2一定比5多)
//  则问题更改为识别5 / 5平方 / 5三次方的数量

class Solution {
public:
	int trailingZeroes(int n) {
		int iter_five = 5;
		int res = 0;
		while (n >= iter_five)
		{
			res += n / iter_five;
			if (iter_five > 1000000000) break;  //防止溢出
			iter_five *= 5;
		}
		return res;
	}
};
