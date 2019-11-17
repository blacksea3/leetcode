#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int maxr = grid.size();
		int maxc = grid[0].size();
		for (int i = 0; i < k; ++i)
		{
			vector<vector<int>> next(maxr, vector<int>(maxc, -9999));
			for (int r = 0; r < maxr; ++r)
			{
				for (int c = 1; c < maxc; ++c)
				{
					next[r][c] = grid[r][c];
				}
			}
			for (int r = 1; r < maxr; ++r)
			{
				next[r][0] = grid[r - 1][maxc - 1];
			}
			next[0][0] = grid[maxr - 1][maxc - 1];

			grid = next;
		}
		return grid;
	}
};
