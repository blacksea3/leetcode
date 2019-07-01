#include "public.h"

//16ms, 95.20%
//¿´´úÂë°É

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;

		int thefuck3 = (int)pow(3, 19);

		return (thefuck3%n == 0);
	}
};
