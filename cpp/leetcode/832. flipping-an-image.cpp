#include "public.h"

//24ms, 37.20%
//Ä£Äâ, Á½²½

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int r = 0; r < A.size(); ++r)
		{
			for (int c = 0; c < A[0].size() / 2; ++c)
			{
				swap(A[r][c], A[r][A.size() - 1 - c]);
				A[r][c] = (A[r][c] == 0) ? 1 : 0;
				A[r][A.size() - 1 - c] = (A[r][A.size() - 1 - c] == 0) ? 1 : 0;
			}
			if (A[0].size() % 2)
				A[r][A[0].size() / 2] = (A[r][A[0].size() / 2] == 0) ? 1 : 0;
		}
		return A;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> A = { {1,1,0},{1,0,1}, {0,0,0} };
	auto res = s->flipAndInvertImage(A);
	return 0;
}
*/
