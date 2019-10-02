#include "public.h"

//36ms, 94.53%
//dp问题
//建立vector表示[0, n-1]这n个数字是否是质数

class Solution {
public:
	int countPrimes(int n) {
		int res = 1;
		if (n <= 2) return 0;
		vector<bool> vb(n, true);
		//仅对小于根号n的奇数的奇数倍进行判断
		for (int i = 3; i < sqrt(n); i += 2)
		{
			if (vb[i])
			{
				int j = i * i;
				while (j < n)
				{
					vb[j] = false;
					j += 2 * i;
				}
			}
		}

		for (int loc = 3; loc < n; loc += 2)
			if (vb[loc]) res++;

		return res;
	}
};
