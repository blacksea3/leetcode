#include "public.h"


//
//先从0到2^n-1排一次, 然后全部求异或
//贪心

class Solution {
private:
	vector<int> perm(int n)
	{
		vector<int> v;
		v.emplace_back(0);
		for (int time = 0; time < n; ++time)
		{
			vector<int> temp = v;
			for (int index = temp.size() - 1; index >= 0; --index) v.emplace_back((size_t)pow(2, time) + temp[index]);
		}
		return v;
	}

public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> res((size_t)pow(2, n));

		vector<int> yihuo = perm(n);

		for (int i = 0; i < (size_t)pow(2, n); ++i)
		{
			res[i] = start ^ yihuo[i];
		}
		return res;
	}
};