#include "public.h"

//16ms, 80.72%
//DFS, ����������½�ظ�ֵ2

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
		int maxrow = grid.size() - 1;  //�ر�ע��:�˴���maxrow=row��-1
		if (maxrow < 0) return 0;
		int maxcolumn = grid[0].size() - 1;  //�ر�ע��:�˴���maxcolumn=column��-1
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
