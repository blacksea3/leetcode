#include "public.h"

//68ms, 97.55%
//注意只有一个岛屿而且没有湖
//对于岛屿: 每当周围多一个岛它的周长贡献减1, 每个岛的最大周长贡献是4
//直接双重循环

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;
		int gSize = grid.size();
		int g0Size = grid[0].size();
		for (int r = 0; r < gSize; ++r)
			for (int c = 0; c < g0Size; ++c)
			{
				if (grid[r][c] == 1)
				{
					int contribute = 4;
					if (r > 0 && grid[r - 1][c] == 1) contribute--;
					if (c > 0 && grid[r][c - 1] == 1) contribute--;
					if (r < (gSize - 1)&& grid[r + 1][c] == 1) contribute--;
					if (c < (g0Size - 1) && grid[r][c + 1] == 1) contribute--;
					res += contribute;
				}
			}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> grid = { {0,1,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,0} };
	cout << s->islandPerimeter(grid);
	return 0;
}
*/
