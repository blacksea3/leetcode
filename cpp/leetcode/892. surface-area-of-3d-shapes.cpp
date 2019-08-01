#include "public.h"

//16ms, 45.39%
//模拟:
//上下: 不是0的个数
//左: 假设最左边是0, 则每次加上delta(当前格-左边格)
//右: 假设最右边是0, 则每次加上delta(当前格-右边格)
//前后同理

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int res = 0;
		int rows = grid.size();
		int cols = grid[0].size();

		//上下
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				res += (grid[r][c] > 0) ? 2 : 0;
			}
		}

		//左右
		for (int r = 0; r < rows; ++r)
		{
			res += grid[r][0];
			for (int c = 1; c < cols; ++c)
			{
				res += abs(grid[r][c] - grid[r][c - 1]);
			}
			res += grid[r][cols - 1];
		}

		//前后
		for (int c = 0; c < cols; ++c)
		{
			res += grid[0][c];
			for (int r = 1; r < rows; ++r)
			{
				res += abs(grid[r][c] - grid[r - 1][c]);
			}
			res += grid[rows - 1][c];
		}
		return res;
	}
};
