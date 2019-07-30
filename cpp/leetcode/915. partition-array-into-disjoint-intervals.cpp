#include "public.h"

//48ms, 65.79%
//双端扫描
//求从左边起的最大和从右边起的最小

class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		vector<int> lmax(A.size());
		vector<int> rmin(A.size());

		int pmax = -1;
		for (int i = 0; i < A.size(); ++i)
		{
			pmax = max(pmax, A[i]);
			lmax[i] = pmax;
		}
		int pmin = 1000001;
		for (int i = A.size() - 1; i >= 0; --i)
		{
			pmin = min(pmin, A[i]);
			rmin[i] = pmin;
		}

		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (lmax[i] <= rmin[i + 1]) return i + 1;
		}
		return -999; //dump
	}
};

