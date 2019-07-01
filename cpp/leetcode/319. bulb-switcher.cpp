#include "public.h"

//4ms, 88.12%
//只有完全平方数有奇数个质因子
//随便列举一个n, 例如列举一下n=10就知道规律了

class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};
