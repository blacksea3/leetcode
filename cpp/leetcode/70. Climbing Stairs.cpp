#include "public.h"

//8ms, 75.14%

//Here is a Fibonacci sequence

class Solution {
public:
	int climbStairs(int n) {
		//problem ensure that n >= 1
		if (n <= 2) return n;

		int n1 = 1;
		int n2 = 2;
		for (int i = 2; i < n; i++)
		{
			n1 += n2;
			swap(n1, n2);
		}

		return n2;
	}
};