#include "public.h"

//4ms, 90.11%
//数学问题

class Solution {
public:
	bool canWinNim(int n) {
		return (n % 4 != 0);
	}
};
