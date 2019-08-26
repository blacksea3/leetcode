#include "public.h"

//4ms, 84.49%
//��������, ��sqrt(num)��ʼ��������, ����sqrt(num), ��Ķ��ǳɶԳ��ֵ�

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
