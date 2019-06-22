#include "public.h"

//simple solution, 8ms, 79.46%

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		//ÆÓËØµÄÎ»ÔËËã

		uint32_t res = 0;
		for (int i = 0; i < 32; i++)
		{
			res <<= 1;
			if (n & 0x00000001)
				res |= 0x00000001;
			n >>= 1;
		}
		return res;
	}
};

