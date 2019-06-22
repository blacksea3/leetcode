#include "public.h"

//simple problem, 数学, 4ms, 92.65%
//就是判断5个次数(因为2一定比5多)
//不停地除以5缩小值

class Solution {
public:
	int trailingZeroes(int n) {
		//识别5/5平方/5三次方的数量
		//你只需要搞清楚n/5 ; n/25....的值就可

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
