#include "public.h"

//40ms, 34.88%
//max(���ֵ-K - ��Сֵ+K, 0)

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int maxe = *max_element(A.begin(), A.end());
		int mine = *min_element(A.begin(), A.end());
		return max(maxe - K - mine - K, 0);
	}
};
