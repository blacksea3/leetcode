#include "public.h"

//����vector��ʾ0-n-1��n�������Ƿ�������, 52ms, 80.99%

class Solution {
public:
	int countPrimes(int n) {
		int res = 1;
		if (n <= 2) return 0;
		vector<bool> vb(n, true);
		//����С�ڸ���n�������������������ж�
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
