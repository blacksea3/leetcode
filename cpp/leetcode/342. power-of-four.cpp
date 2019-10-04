#include "public.h"

//4ms, 78.44%

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) return false;

		while (!(num % 4)) num /= 4;
		return (num == 1);

	}
};
