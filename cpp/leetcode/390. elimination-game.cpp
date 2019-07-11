#include "public.h"

//8ms, 88.39%
//考虑以下的两个规律: 
//1、 如果输入是 a 而输出是 b ，那么输入是 2a 时的输出就是 2 * (a - b + 1)
//    例如：1 2 3 4 5 6 7 8 9 10, 先变成 2 4 6 8 10当作 5 4 3 2 1如果5的时候是2那么现在就是8
//2、奇数情况等同于-1的偶数情况

class Solution {
public:
	int lastRemaining(int n) {
		if (n == 1) return 1;
		else return 2 * (n / 2 - lastRemaining(n / 2) + 1);
	}
};
