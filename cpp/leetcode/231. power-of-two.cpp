#include "public.h"

//0ms, 100%
//Œª‘ÀÀ„

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		while (n > 1)
		{
			if (n & 1) return false;
			n >>= 1;
		}
		return true;
	}
};
