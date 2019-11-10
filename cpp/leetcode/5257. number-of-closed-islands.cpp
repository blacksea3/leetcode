#include "public.h"

//
//DFS, 先对边缘扫一遍, 陆地全部写成2, 然后对中间扫, 每次扫一个写成2, 结果加1

class Solution {
private:
	void DFS(vector<vector<int>>& grid, int r, int c)
	{
		int mr = grid.size();
		int mc = grid[0].size();

		grid[r][c] = 2;

		if (r > 0 && grid[r - 1][c] == 0) DFS(grid, r - 1, c);
		if (c > 0 && grid[r][c - 1] == 0) DFS(grid, r, c - 1);
		if (r < (mr - 1) && grid[r + 1][c] == 0) DFS(grid, r + 1, c);
		if (c < (mc - 1) && grid[r][c + 1] == 0) DFS(grid, r, c + 1);
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		int res = 0;

		//扫周围
		int mr = grid.size();
		int mc = grid[0].size();

		for (int r = 0; r < mr; ++r)
		{
			if (grid[r][0] == 0) DFS(grid, r, 0);
			if (grid[r][mc - 1] == 0) DFS(grid, r, mc - 1);
		}

		for (int c = 0; c < mc; ++c)
		{
			if (grid[0][c] == 0) DFS(grid, 0, c);
			if (grid[mr - 1][c] == 0) DFS(grid, mr - 1, c);
		}

		//扫中间
		for (int r = 1; r < (mr - 1); ++r)
		{
			for (int c = 1; c < (mc - 1); ++c)
			{
				if (grid[r][c] == 0)
				{
					DFS(grid, r, c);
					res++;
				}
			}
		}
		return res;
	}
};
