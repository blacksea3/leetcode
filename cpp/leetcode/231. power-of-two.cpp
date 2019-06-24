#include "public.h"

//4ms, 90.47%
//DC: ·ÖÖÎ·¨

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		while (n > 1)
		{
			if (n % 2) return false;
			n /= 2;
		}
		return true;
	}
};
