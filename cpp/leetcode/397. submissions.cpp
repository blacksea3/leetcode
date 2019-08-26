#include "public.h"

//8ms, 64.90%
//±©Á¦, µÝ¹é

class Solution {
private:
	int res = INT_MAX;
		void recu(int n, int pre)
	{
		if (n == 1) res = min(res, pre);
		else if (n % 2 == 0) recu(n / 2, pre + 1);
		else
		{
			recu(n + 1, pre + 1);
			recu(n - 1, pre + 1);
		}
	}
public:
	int integerReplacement(int n) {
		recu(n, 0);
		return res;
	}
};
