#include "public.h"

//100ms, 43.33%
//从中心点开始扩展, 若四周值都与其相同则中心点不被保存至待修改点
//否则中心点被保存至待修改点
//周围点继续扩散

class Solution {
private:
	void DFS(const vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<bool>>& need_color, int pr, int pc, int color)
	{
		bool iscentor = true;
		visited[pr][pc] = true;
		if (pr > 0 && grid[pr - 1][pc] == color)
		{
			if (!visited[pr - 1][pc]) DFS(grid, visited, need_color, pr - 1, pc, color);
		}
		else iscentor = false;
		if (pc > 0 && grid[pr][pc - 1] == color)
		{
			if (!visited[pr][pc - 1]) DFS(grid, visited, need_color, pr, pc - 1, color);
		}
		else iscentor = false;
		if (pr < grid.size() - 1 && grid[pr + 1][pc] == color)
		{
			if (!visited[pr + 1][pc]) DFS(grid, visited, need_color, pr + 1, pc, color);
		}
		else iscentor = false;
		if (pc < grid[0].size() - 1 && grid[pr][pc + 1] == color)
		{
			if (!visited[pr][pc + 1]) DFS(grid, visited, need_color, pr, pc + 1, color);
		}
		else iscentor = false;
		if (!iscentor) need_color[pr][pc] = true;
	}

public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		vector<vector<bool>> need_color(grid.size(), vector<bool>(grid[0].size(), false));
		DFS(grid, visited, need_color, r0, c0, grid[r0][c0]);

		for (int r = 0; r < grid.size(); ++r)
			for (int c = 0; c < grid[0].size(); ++c)
				if (need_color[r][c]) grid[r][c] = color;

		return grid;
	}
};

