#include "public.h"

//0ms, 100%
//�������2, ��������3

class Solution {
public:
	int integerBreak(int n) {
		if (n <= 3) return n - 1;
		else
		{
			if (n % 3 == 0) return (int)pow(3, n / 3);
			else if (n % 3 == 1) return (int)pow(3, n / 3) * 2;
			else return (int)pow(3, n / 3 - 1) * 4;
		}
	}
};

