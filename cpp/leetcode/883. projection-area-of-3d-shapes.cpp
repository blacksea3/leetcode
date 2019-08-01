#include "public.h"

//12ms, 77.13%
//simple solution

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int res = 0;
		for (int r = 0; r < grid.size(); ++r)
		{
			for (int c = 0; c < grid[0].size(); ++c)
			{
				res += (grid[r][c] > 0) ? 1 : 0;
			}
		}

		for (int r = 0; r < grid.size(); ++r)
		{
			int pmax = 0;
			for (int c = 0; c < grid[0].size(); ++c)
			{
				pmax = max(pmax, grid[r][c]);
			}
			res += pmax;
		}

		for (int c = 0; c < grid[0].size(); ++c)
		{
			int pmax = 0;
			for (int r = 0; r < grid.size(); ++r)
			{
				pmax = max(pmax, grid[r][c]);
			}
			res += pmax;
		}
		return res;
	}
};
