#include "public.h"

//4ms, 83.45%
//Î»ÔËËã

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			res += (n & 1);
			n >>= 1;
		}
		return res;
	}
};
