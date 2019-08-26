#include "public.h"

//4ms, 83.42%
//直接算, 两个数来回算

class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		else
		{
			int num1 = 0;
			int num2 = 1;

			while (N > 1)
			{
				int temp = num2 + num1;
				num1 = num2;
				num2 = temp;
			}
			return num2;
		}
	}
};
