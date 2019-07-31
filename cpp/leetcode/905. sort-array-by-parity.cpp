#include "public.h"

//40ms, 80.53%
//simple solution

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> v(A.size());
		int vloc = 0;
		int aloc = 0;
		while (aloc < A.size())
		{
			if (A[aloc] % 2 == 0) v[vloc++] = A[aloc];
			aloc++;
		}
		aloc = 0;
		while (aloc < A.size())
		{
			if (A[aloc] % 2) v[vloc++] = A[aloc];
			aloc++;
		}
		return v;
	}
};
