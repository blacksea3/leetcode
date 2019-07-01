#include "public.h"

//8ms, 80.94%
//O(1)时间复杂度, 那么就是数学题

class Solution {
public:
	int addDigits(int num) {
		return ((num - 1) % 9) + 1;
	}
};
