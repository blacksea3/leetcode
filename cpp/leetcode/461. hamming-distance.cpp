#include "public.h"

//0ms, 100%
//求异或, 看1的个数

class Solution {
public:
	int hammingDistance(int x, int y) {
		int x_or = x ^ y;
		int res = 0;
		while (x_or > 0)
		{
			if (x_or % 2) res++;
			x_or /= 2;
		}
		return res;
	}
};
