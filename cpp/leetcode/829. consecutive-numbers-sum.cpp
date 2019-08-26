#include "public.h"

//8ms, 87.27%
//找规律, 分奇偶, 直接看代码

class Solution {
public:
	int consecutiveNumbersSum(int N) {
		int res = 0;

		//奇数
		for (int i = 1; ; i += 2)
		{
			if (N / i <= (i / 2)) break;
			if (N%i == 0) res++;
		}

		//偶数
		for (int i = 2; ; i += 2)
		{
			if (N / i < (i / 2)) break;
			if (N%i == (i / 2)) res++;
		}
		return res;
	}
};
