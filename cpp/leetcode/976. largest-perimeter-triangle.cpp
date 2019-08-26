#include "public.h"

//88ms, 28.77%
//三角形需要满足: big < (medium + small)
//连续取连续三个最长的

class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());

		int res = 0;

		for (int i = 0; i < A.size() - 2; ++i)
		{
			if (A[i] < (A[i + 1] + A[i + 2]))
			{
				res = A[i] + A[i + 1] + A[i + 2];
				break;
			}
		}
		return res;
	}
};
