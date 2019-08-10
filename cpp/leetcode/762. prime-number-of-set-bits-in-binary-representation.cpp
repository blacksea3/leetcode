#include "public.h"

//40ms, 40.00%
//±©Á¦

class Solution {
private:
	bool isprimebits(int n)
	{
		int primenum = 0;
		while (n > 0)
		{
			if (n % 2) primenum++;
			n /= 2;
		}
		if (primenum == 2 || primenum == 3 || primenum == 5 || primenum == 7 || primenum == 11 || primenum == 13 || primenum == 17 || primenum == 19) return true;
		return false;
	}

public:
	int countPrimeSetBits(int L, int R) {
		int res = 0;
		for (int i = L; i <= R; ++i)
		{
			if (isprimebits(i)) res++;
		}
		return res;
	}
};
