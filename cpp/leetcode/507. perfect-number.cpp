#include "public.h"

//4ms, 84.49%
//暴力就行, 从sqrt(num)开始找正因子, 除了sqrt(num), 别的都是成对出现的

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1) return false;
		int presum = 0;

		for (int i = (int)sqrt(num); i >= 2; --i)
		{
			if (num%i == 0)
			{
				if (num / i == i) presum += i;
				else presum += (i + num / i);
				if (presum >= num) return false;
			}
		}

		return (presum + 1) == num;

	}
};
