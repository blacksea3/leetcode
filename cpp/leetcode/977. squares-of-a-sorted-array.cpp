#include "public.h"

//180ms, 43.08%
//重新排序, 然后平方

class Solution {
private:
	static bool msort(const int& a, const int& b)
	{
		return abs(a) > abs(b);
	}

public:
	vector<int> sortedSquares(vector<int>& A) {
		sort(A.begin(), A.end(), msort);

		for (int i = 0; i < A.size(); ++i)
			A[i] = A[i] * A[i];
		return A;
	}
};
