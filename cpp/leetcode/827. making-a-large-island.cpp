#include "public.h"

//672ms, 14.63%
//暴力: 直接寻找能放的地方, 然后DFS不就行了???

class Solution {
private:
	void DFS(vector<vector<int>>& grid, int& isize, int pr, int pc)
	{
		isize++;
		grid[pr][pc] = 2;
		if (pr > 0 && grid[pr - 1][pc] == 1) DFS(grid, isize, pr - 1, pc);
		if (pc > 0 && grid[pr][pc - 1] == 1) DFS(grid, isize, pr, pc - 1);
		if (pr < grid.size() - 1 && grid[pr + 1][pc] == 1) DFS(grid, isize, pr + 1, pc);
		if (pc < grid[0].size() - 1 && grid[pr][pc + 1] == 1) DFS(grid, isize, pr, pc + 1);
	}

public:
	int largestIsland(vector<vector<int>>& grid) {
		//特殊情况
		int rs = grid.size();
		int cs = grid[0].size();

		bool isallone = true;

		for (int r = 0; r < rs; ++r)
			for (int c = 0; c < cs; ++c)
			{
				if (grid[r][c] == 0)
				{
					isallone = false;
					break;
				}
			}
		if (isallone) return rs * cs;
		else
		{
			int res = 0;

			for (int r = 0; r < rs; ++r)
				for (int c = 0; c < cs; ++c)
				{
					if (grid[r][c] == 0)
					{
						int presize = 0;
						vector<vector<int>> cpgrid = grid;
						DFS(cpgrid, presize, r, c);
						res = max(res, presize);
					}
				}
			return res;
		}
	}
};
