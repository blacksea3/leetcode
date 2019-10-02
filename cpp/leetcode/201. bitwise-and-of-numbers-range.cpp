#include "public.h"

//12ms, 94.22%
//相当于求m和n的从最高位开始的连续相同位

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int res = 0;
		int k = 0x40000000; // 非负整数的最大二次幂
		while (k > 0 && (m & k) == (n & k))
		{
			res |= k & m;
			k >>= 1;
		}
		return res;
	}
};
