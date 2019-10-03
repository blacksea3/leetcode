#include "public.h"

//16ms, 88.65%
//使用极大的3的幂次来操作

class Solution {
public:
	bool isPowerOfThree(int n) {
		//int thefuck3=(int)pow(3,19);
		return (n > 0) && (1162261467 % n == 0);
	}
};
