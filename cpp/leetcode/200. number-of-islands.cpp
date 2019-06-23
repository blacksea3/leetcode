#include "public.h"

//DFS, 16ms, 91.76%

class Solution {
private:
	void DFS(vector<vector<char>>& grid, int row, int column, const int& maxrow, const int& maxcolumn)
	{
		grid[row][column] = '2';
		if ((row > 0) && (grid[row - 1][column] == '1')) DFS(grid, row - 1, column, maxrow, maxcolumn);
		if ((row < maxrow) && (grid[row + 1][column] == '1')) DFS(grid, row + 1, column, maxrow, maxcolumn);
		if ((column > 0) && (grid[row][column - 1] == '1')) DFS(grid, row, column - 1, maxrow, maxcolumn);
		if ((column < maxcolumn) && (grid[row][column + 1] == '1')) DFS(grid, row, column + 1, maxrow, maxcolumn);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		//DFS,对搜索过的陆地赋值2

		//特殊情况
		int maxrow = grid.size() - 1;
		if (maxrow < 0) return 0;
		int maxcolumn = grid[0].size() - 1;
		if (maxcolumn < 0) return 0;
		int res = 0;

		for (int row = 0; row <= maxrow; ++row)
			for (int col = 0; col <= maxcolumn; ++col)
			{
				if (grid[row][col] == '1')
				{
					DFS(grid, row, col, maxrow, maxcolumn);
					res++;
				}
			}
		return res;
	}
};

