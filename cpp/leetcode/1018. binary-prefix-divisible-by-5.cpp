#include "public.h"

//20ms, 81.80%
//สýัง
//2*x mod 5 == 2*(x mod 5)

class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> res(A.size(), false);

		int hismod = 0;

		for (int i = 0; i < A.size(); ++i)
		{
			hismod = hismod * 2 + A[i] % 5;
			hismod = hismod % 5;
			if (hismod == 0) res[i] = true;
		}

		return res;
	}
};
