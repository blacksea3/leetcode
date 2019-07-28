#include "public.h"

//52ms, 96.31%
//°´ÁÐÅÐ¶Ï

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int res = 0;
		for (int c = 0; c < A[0].size(); ++c)
		{
			for (int r = 0; r < A.size() - 1; ++r)
			{
				if (A[r][c] > A[r + 1][c])
				{
					res++;
					break;
				}
			}
		}
		return res;
	}
};
