#include "public.h"

//16ms, 77.40%
//DP problem

class Solution {
public:
	int nthUglyNumber(int n) {
		array<int, 1690> uglys;
		uglys[0] = 1;

		int nextloc = 1;
		int p2 = 0;
		int p3 = 0;
		int p5 = 0;
		while (nextloc < n)
		{
			int tp2 = uglys[p2] * 2;
			int tp3 = uglys[p3] * 3;
			int tp5 = uglys[p5] * 5;
			int temp = min(tp2, min(tp3, tp5));
			uglys[nextloc++] = temp;
			if (tp2 == temp) ++p2;
			if (tp3 == temp) ++p3;
			if (tp5 == temp) ++p5;
		}
		return uglys[n - 1];
	}
};
