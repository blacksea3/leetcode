#include "public.h"

//12ms, 79.16%
//DP问题, 逐行更新
//dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		//特殊情况
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		if (m == 0) return 0;

		vector<long> dp(m, 0);
		dp[0] = grid[0][0];
		for (int j = 1; j < m; j++) dp[j] = dp[j - 1] + grid[0][j];

		for (int i = 1; i < n; i++)
		{
			dp[0] += grid[i][0];
			for (int j = 1; j < m; j++)
			{
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
			}
		}
		return dp[m - 1];
	}
};
