#include "public.h"

//8ms, 96.84%

//Math problem, consider the border input carefully!

#define LIMIT 0x80000000

class Solution {
public:
	int divide(int dividend, int divisor) {
		//the FUCK border input
		//only this condition may overflow:
		// INT_MIN/-1 =>(>) INT_MAX
		// INT_MIN/1 = INT_MIN

		if (dividend == INT_MIN)
			if (divisor == -1) return INT_MAX;
			else if (divisor == 1) return INT_MIN;
			else;

		bool ispositive = true;
		if ((dividend > 0) ^ (divisor > 0)) ispositive = false;
		unsigned int n_dividend = (dividend == INT_MIN) ? LIMIT : abs(dividend);
		unsigned int n_divisor = (divisor == INT_MIN) ? LIMIT : abs(divisor);

		int res = 0;
		for (int i = 31; i >= 0; i--)
		{
			if ((n_dividend >> i) >= n_divisor)  //避免溢出,不要直接divisor<<i
			{
				n_dividend -= (n_divisor << i);
				res += (1 << i);
			}
		}
		return (ispositive) ? res : -1 * res;
	}
};