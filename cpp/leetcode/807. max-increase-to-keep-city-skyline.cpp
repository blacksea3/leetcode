#include "public.h"

//8ms, 92.54%
//行列扫描, 当前数字可以增加至行列最大数中的最小数

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> maxr(grid.size());
		vector<int> maxc(grid[0].size());

		for (int r = 0; r < grid.size(); ++r)
		{
			int tempmax = INT_MIN;
			for (int c = 0; c < grid[0].size(); ++c)
			{
				tempmax = max(tempmax, grid[r][c]);
			}
			maxr[r] = tempmax;
		}

		for (int c = 0; c < grid[0].size(); ++c)
		{
			int tempmax = INT_MIN;
			for (int r = 0; r < grid.size(); ++r)
			{
				tempmax = max(tempmax, grid[r][c]);
			}
			maxc[c] = tempmax;
		}

		int res = 0;
		for (int r = 0; r < grid.size(); ++r)
		{
			for (int c = 0; c < grid[0].size(); ++c)
			{
				res += min(maxr[r], maxc[c]) - grid[r][c];
			}
		}
		return res;
	}
};
