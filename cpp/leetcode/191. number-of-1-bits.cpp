#include "public.h"

//simple solution, 8ms, 79.51%
//λ����

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		//λ����
		for (int i = 0; i < 32; i++)
		{
			if (n & 0x00000001) res++;
			n >>= 1;
		}
		return res;
	}
};

