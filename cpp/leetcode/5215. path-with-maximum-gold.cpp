#include "public.h"

//
//±©Á¦DFS

class Solution {
private:
	int gblres;
	void DFS(vector<vector<int>> const& grid, vector<vector<bool>>& issearched, int r, int c, int prev)
	{
		int mr = grid.size();
		int mc = grid[0].size();
		prev += grid[r][c];
		gblres = max(gblres, prev);
		issearched[r][c] = true;

		if (r > 0 && grid[r - 1][c] != 0 && !issearched[r - 1][c]) DFS(grid, issearched, r - 1, c, prev);
		if (c > 0 && grid[r][c - 1] != 0 && !issearched[r][c - 1]) DFS(grid, issearched, r, c - 1, prev);
		if (r < mr - 1 && grid[r + 1][c] != 0 && !issearched[r + 1][c]) DFS(grid, issearched, r + 1, c, prev);
		if (c < mc - 1 && grid[r][c + 1] != 0 && !issearched[r][c + 1]) DFS(grid, issearched, r, c + 1, prev);

		prev -= grid[r][c];
		issearched[r][c] = false;
	}


public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int r = grid.size();
		int c = grid[0].size();
		gblres = 0;

		vector<vector<bool>> issearched(r, vector<bool>(c, false));

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (grid[i][j] != 0)
				{
					vector<vector<bool>> inis = issearched;
					DFS(grid, inis, i, j, 0);
				}
			}
		}
		return gblres;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> grid = { {0, 6, 0}, {5,8,7},{0,9,0} };
	cout << s->getMaximumGold(grid);
	return 0;
}
*/
