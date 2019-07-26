#include "public.h"

//108ms, 7.48%
//考虑到grid大小不大, 可以使用巨大的DFS

class Solution {
private:
	int endr;
	int endc;
	int res = 0;
	void DFS(const vector<vector<int>>& grid, int spaces, vector<vector<bool>> issearched, int r, int c)
	{
		issearched[r][c] = true;
		spaces--;
		if (spaces == 0)
		{
			if ((r > 0) && (grid[r - 1][c] == 2)) res++;
			if ((c > 0) && (grid[r][c - 1] == 2)) res++;
			if ((r < grid.size() - 1) && (grid[r + 1][c] == 2)) res++;
			if ((c < grid[0].size() - 1) && (grid[r][c + 1] == 2)) res++;
		}
		else
		{
			if ((r > 0) && !issearched[r - 1][c] && (grid[r - 1][c] == 0)) DFS(grid, spaces, issearched, r - 1, c);
			if ((c > 0) && !issearched[r][c - 1] && (grid[r][c - 1] == 0)) DFS(grid, spaces, issearched, r, c - 1);
			if ((r < grid.size() - 1) && !issearched[r + 1][c] && (grid[r + 1][c] == 0)) DFS(grid, spaces, issearched, r + 1, c);
			if ((c < grid[0].size() - 1) && !issearched[r][c + 1] && (grid[r][c + 1] == 0)) DFS(grid, spaces, issearched, r, c + 1);
		}
	}

public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int sps = 0;
		int star;
		int stac;

		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
				{
					star = i;
					stac = j;
				}
				else if (grid[i][j] == 2)
				{
					endr = i;
					endc = j;
				}
				else if (grid[i][j] == 0) sps++;
			}
		}

		vector<vector<bool>> issearched(grid.size(), vector<bool>(grid[0].size(), false));

		DFS(grid, sps + 1, issearched, star, stac);

		return res;
	}
};
