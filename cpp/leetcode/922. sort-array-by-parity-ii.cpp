#include "public.h"

//120ms, 87.59%
//·Ö¿ª·Å

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> res(A.size());
		int locodd = 0;
		int loceven = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i] % 2 == 0) res[2 * (loceven++)] = A[i];
			else res[2 * (locodd++) + 1] = A[i];
		}
		return res;
	}
};
