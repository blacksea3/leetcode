#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> v(n, vector<int>(m, 0));

		for (auto& ind : indices)
		{
			for (int r = 0; r < n; ++r) v[r][ind[1]]++;
			for (int c = 0; c < m; ++c) v[ind[0]][c]++;
		}

		int res = 0;
		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < m; ++c)
			{
				res += v[r][c] % 2;
			}
		}
		return res;
	}
};
