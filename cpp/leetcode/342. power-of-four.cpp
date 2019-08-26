#include "public.h"

//4ms, 88.89%
//simple solution

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) return false;

		while (num % 4 == 0) num /= 4;
		return (num == 1);

	}
};
