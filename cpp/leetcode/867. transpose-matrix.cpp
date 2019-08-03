#include "public.h"

//40ms, 58.92%
//simple solution

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> res(A[0].size(), vector<int>(A.size()));

		for (int c = 0; c < A[0].size(); ++c)
		{
			for (int r = 0; r < A.size(); ++r)
			{
				res[c][r] = A[r][c];
			}
		}
		return res;
	}
};
