#include "public.h"

//12ms, 32.34%
//数量级很小直接暴力

class Solution {
private:
	//必须保证输入坐标合法
	bool issquare(const vector<vector<int>>& grid, int str, int stc)
	{
		set<int> s;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (grid[str + i][stc + j] > 9 || grid[str + i][stc + j] < 1) return false;
				s.insert(grid[str + i][stc + j]);
			}
		}
		if (s.size() != 9) return false;

		int num = grid[str][stc] + grid[str][stc + 1] + grid[str][stc + 2];
		for (int i = 0; i < 3; ++i)
		{
			int tempr = 0;
			for (int j = 0; j < 3; ++j)
			{
				tempr += grid[str + i][stc + j];
			}
			if (tempr != num) return false;
			tempr = 0;
			for (int j = 0; j < 3; ++j)
			{
				tempr += grid[str + j][stc + i];
			}
			if (tempr != num) return false;
		}

		if ((grid[str][stc] + grid[str + 1][stc + 1] + grid[str + 2][stc + 2]) != num) return false;
		if ((grid[str + 2][stc] + grid[str + 1][stc + 1] + grid[str][stc + 2]) != num) return false;
		return true;
	}


public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int res = 0;
		for (int r = 0; r < (int)grid.size() - 2; ++r)
		{
			for (int c = 0; c < (int)grid[0].size() - 2; ++c)
			{
				if (issquare(grid, r, c)) res++;
			}
		}
		return res;
	}
};
